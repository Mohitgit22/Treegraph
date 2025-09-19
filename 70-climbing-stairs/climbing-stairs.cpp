class Solution {
public:
    // int recur(int n, vector<int>& dp){
    //       if(n <= 2){
    //         dp[n] = n;
    //         return dp[n];
    //       }

    //       if(dp[n] != -1) return dp[n];

    //       dp[n] =  recur(n-1, dp) + recur(n-2, dp);
    //       return dp[n];
    // }
    int climbStairs(int n) {
         if(n <= 2) return n;
         
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i < n+1; i++){
              dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};