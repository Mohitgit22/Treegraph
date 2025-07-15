class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
            }
        }
       
        int time = 0;
        int dx[4] = { 0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!que.empty()){
            int sz = que.size();
            bool rottedThisMinute = false;

            while(sz > 0){
               int x = que.front().first;
               int y = que.front().second;
               que.pop();
               sz--;
               for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newx < m and newy >= 0 and newy < n and grid[newx][newy] == 1){
                     grid[newx][newy] = 2;
                     que.push({newx, newy});
                     rottedThisMinute = true;
                }
              }  
            }
            if(rottedThisMinute) time++;
        }

         for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
      return time;
    }
};