class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i =0; i< n; i++){
            if(!vis[i]){
                cnt++;
                bfs(adj, i, vis);
            }
        }
        return cnt;
    }

    void bfs(vector<vector<int>>& adj, int u, vector<bool>& vis){
        queue<int> que;

        que.push(u);
        vis[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v: adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
};