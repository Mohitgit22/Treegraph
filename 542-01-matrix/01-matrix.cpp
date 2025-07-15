class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int, int>, int>> que;
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    que.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

       int dx[4] = {0, 0, -1, 1};
       int dy[4] = {-1, 1, 0, 0};

        while(!que.empty()){
            int x = que.front().first.first;
            int y = que.front().first.second;
            int dist = que.front().second;
            que.pop();
            
            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newx < n and newy >= 0 and newy < m and mat[newx][newy] == 1 and !vis[newx][newy]){
                    vis[newx][newy] = true;
                    mat[newx][newy] = dist+1;
                    que.push({{newx, newy}, dist + 1});
                }
            }
        }
    return mat;

    }
};