class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>> que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({0,{i, j}});
                }
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
       
       int t = 0;
       while(!que.empty()){
         auto front = que.front();
         que.pop();
         t = front.first;
         int x = front.second.first;
         int y = front.second.second;

         for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy] == 1){
                grid[newx][newy] = 2;
                que.push({t+1, {newx, newy}});
            }
         }
       }
       
       for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

       return t;
    }
};