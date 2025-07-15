class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         queue<pair<int, int>> que;
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++) {
        //         if(grid[i][j] == 2){
        //             que.push({i, j});
        //         }
        //     }
        // }

        que.push({sr, sc});
        int initialcolor = image[sr][sc];
        vis[sr][sc] = true;

        image[sr][sc] = color;
       
        int dx[4] = { 0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!que.empty()){
            int sz = que.size();
            while(sz > 0){
               int x = que.front().first;
               int y = que.front().second;
               que.pop();
               sz--;
                for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx >= 0 and newx < m and newy >= 0 and newy < n and image[newx][newy] == initialcolor and vis[newx][newy] == false){
                     image[newx][newy] = color;
                     que.push({newx, newy});
                     vis[newx][newy] = true;
                }
              }  
            }
        }
        
      return image;
    }
};