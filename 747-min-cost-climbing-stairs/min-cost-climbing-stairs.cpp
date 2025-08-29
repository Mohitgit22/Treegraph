class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i < n+1; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
    
    int recur(int n, vector<int>& cost, vector<int>& dp) {
      if(n == 0 || n == 1){
        dp[n] = 0;
        return dp[n];
      }
      
     if(dp[n]!= -1) 
     return dp[n];

    dp[n] = min(cost[n-1] + recur(n-1, cost, dp) , cost[n-2] + recur(n-2, cost , dp) );
    return dp[n];
    }
};