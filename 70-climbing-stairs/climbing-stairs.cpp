class Solution {
public:
    int recur(int n, vector<int>& dp){
          if(n <= 2){
            dp[n] = n;
            return dp[n];
          }

          if(dp[n] != -1) return dp[n];

          dp[n] =  recur(n-1, dp) + recur(n-2, dp);
          return dp[n];
    }
    int climbStairs(int n) {
         if(n == 1) return 1;
         
        vector<int> dp(n+1, -1);
        return recur(n, dp);
    }
};