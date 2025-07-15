class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         queue<pair<int, int>> que;
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1 ) {
                    if(grid[i][j] == 1){
                        vis[i][j] = true;
                        que.push({i, j});
                    }
                    
                }
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        while(!que.empty()){
             int x = que.front().first;
             int y = que.front().second;
             que.pop();

             for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newx < n and newy >= 0 and newy < m and grid[newx][newy] == 1 and !vis[newx][newy]){
                    vis[newx][newy] = true;
                    que.push({newx, newy});
                }
             }
        }
     
         int cnt= 0 ;
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
               if(!vis[i][j] and grid[i][j] == 1)
               cnt++;
            }
        }
        return cnt;
    }
};

