class Solution {
public:
    // int fib(int n) {
    //     if(n <= 1)
    //     return n;

    //     return fib(n-1) + fib(n-2);
    // }
        
    //    int  top_down(int n, vector<int>& dp){
    //      if(n <= 1){
    //         dp[n] = n;
    //         return dp[n];
    //      }

    //      if(dp[n] != -1) return dp[n];

    //      dp[n] = top_down(n-1, dp) + top_down(n-2, dp);
          
    //      return dp[n];
    //     }


    //bottom up
        // int fib(int n) {
        // if(n <= 1) return n;

        // vector<int>dp(n+1);

        //base case
        // dp[0] = 0;
    //     dp[1] = 1;

    //     for(int i = 2; i < n+1; i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

       //space optimized bottom up
       int fib(int n) {
        if(n <= 1) return n;

        //base case
         int prev2 = 0;
         int prev1 = 1;
         int ans = 0;

        for(int i = 2; i < n+1; i++){
            ans = prev2 + prev1;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};