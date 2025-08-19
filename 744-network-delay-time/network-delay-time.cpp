class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<pair<int, int>>> adj(n);

        for(vector<int>&vec : times){
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            adj[u-1].push_back({v-1, c});
        }

        pq.push({0, k-1});
        vector<int> dij(n, INT_MAX);

        dij[k-1] = 0;
        while(!pq.empty()){
            auto front= pq.top();
            pq.pop();
            int cost = front.first;
            int idx  = front.second;

            for(pair<int, int>& p : adj[idx]){
                int v = p.first;
                int c = p.second;

                if(cost + c < dij[v]){
                    dij[v] = cost + c;
                    pq.push({cost + c, v});
                }
            }
        }
      
      int max_time = INT_MIN;
      for(int it : dij){
        if(it == INT_MAX) return -1;

        max_time = max(max_time, it);
      }
      return max_time;
    }
};