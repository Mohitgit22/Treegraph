class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
       
       queue<pair<pair<int, int>, int>> que;
       int m = grid.size();
       int n = grid[0].size();

    //    bool flag = false;

       for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2)
            que.push({{i, j}, 0});
        }
       }

       int dx[4] = {-1, 1, 0, 0};
       int dy[4] = {0, 0, 1, -1};
       int t = 0;
       while(!que.empty()){
        auto front = que.front();
        que.pop();

        pair<int , int> coord = front.first;
         t = max(t, front.second);
        int x = coord.first;
        int y = coord.second;

        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy] == 1){
                grid[newx][newy] = 2;
                que.push({{newx, newy}, t+1});
            }
        }
       }

       for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1)
            return -1;
        }
       }
       return t;
    }
};