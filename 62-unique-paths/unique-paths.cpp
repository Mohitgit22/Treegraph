class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return recur(m, n, dp);
    }

    int recur(int m , int n, vector<vector<int>>& dp ){
        if(m == 1 and n == 1){
            dp[m][n] =1;
            return 1;
        }

        if(m ==  0 || n ==  0){
            dp[m][n] = 0;
            return 0;
        }
      
       if(dp[m][n] != -1)
       return dp[m][n];

        int ways = recur(m-1, n, dp) + recur(m ,n-1, dp);
        dp[m][n] = ways;
        return ways;
    }
};