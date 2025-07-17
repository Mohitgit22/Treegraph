class Solution {
public:
   typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        int n = grid.size();

        if(grid.size() == 1 and grid[0][0] == 0) return 1;

        vector<vector<int>> dij(n, vector<int>(n, 1e9));
        dij[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});


       int dx[8] = {-1,0, 1, 1,1,0,-1,-1};
       int dy[8] = {1,1,1,0,-1,-1,-1,0};
        while(!pq.empty()) {
         int x = pq.top().second.first;
         int y = pq.top().second.second;
         int d = pq.top().first;
         pq.pop();
       
         for(int i = 0; i < 8; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(newx >= 0 and newx < n and newy >= 0 and newy < n and grid[newx][newy] == 0 and dij[newx][newy] > d + 1 ){
                dij[newx][newy]= d + 1;
                if(newx == n-1 and newy == n-1)
                return dij[newx][newy] + 1;

                pq.push({d+1, {newx, newy}});
            }
         }
        }

        return -1;
    }
};