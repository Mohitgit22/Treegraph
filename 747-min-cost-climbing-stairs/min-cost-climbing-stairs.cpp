class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int prev2 = 0;
        int prev1 = 0;
        int ans = 0;

        for(int i = 2; i < n+1; i++){
            ans = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
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