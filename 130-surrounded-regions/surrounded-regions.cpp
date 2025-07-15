class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> que;
        int n =board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1 ) {
                    if(board[i][j] == 'O'){
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

                if(newx >= 0 and newx < n and newy >= 0 and newy < m and board[newx][newy] == 'O' and !vis[newx][newy]){
                    vis[newx][newy] = true;
                    que.push({newx, newy});
                }
             }
        }

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(vis[i][j]) 
                board[i][j] = 'O';
                else
                board[i][j] = 'X';
            }
        }
    }
};