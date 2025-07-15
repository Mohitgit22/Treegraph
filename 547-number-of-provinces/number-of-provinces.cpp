class Solution {
public:

  void bfs(vector<vector<int>> &adj,int u,  queue<int> &que, vector<bool> &vis, int &cnt) {
      que.push(u);

      while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = true;

        for(int &v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                que.push(v);
            }
        }
      }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < isConnected[i].size(); j++){
                if(isConnected[i][j] == 1 and i != j){
                    adj[i].push_back(j);
                }
            }
        }
       
        queue<int> que;
        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                bfs(adj, i, que, vis, cnt);
            }
        }
        return cnt;
    }  
};