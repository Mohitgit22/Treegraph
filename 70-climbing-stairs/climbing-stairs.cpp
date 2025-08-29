class Solution {
public:
    int top_down(int n, vector<int>& dp) {
        if( n <= 2){
            dp[n] = n;
            return dp[n];
        }

        if(dp[n] != -1)
        return dp[n];

        dp[n] = top_down(n-1, dp) + top_down(n-2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return top_down(n, dp);
    }
};