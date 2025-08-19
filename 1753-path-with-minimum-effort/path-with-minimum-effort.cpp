class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dij(m, vector<int>(n, INT_MAX));
        dij[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        int ans = INT_MIN;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int diff = front.first;
            pair<int, int> p = front.second;
            int x = p.first;
            int y = p.second;

            if(x == m-1 and y == n-1) return diff;

            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newy >= 0 and newx < m and newy < n){
                  int newEffort = max(diff, abs(heights[newx][newy]- heights[x][y]));

                   if(dij[newx][newy] > newEffort){
                    dij[newx][newy] = newEffort;
                    pq.push({newEffort, {newx, newy}});
                   }
                }
            }
        }

        return 0;
    }
};