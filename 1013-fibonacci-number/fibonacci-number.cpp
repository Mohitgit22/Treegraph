class Solution {
public:
    // int fib(int n) {
    //     if(n <= 1)
    //     return n;

    //     return fib(n-1) + fib(n-2);
    // }
        
       int  top_down(int n, vector<int>& dp){
         if(n <= 1){
            dp[n] = n;
            return dp[n];
         }

         if(dp[n] != -1) return dp[n];

         dp[n] = top_down(n-1, dp) + top_down(n-2, dp);
          
         return dp[n];
        }

        int fib(int n) {
        vector<int>dp(n+1, -1);
        return top_down(n, dp);
    }
};