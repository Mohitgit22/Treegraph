class Solution {
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
         vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
         return recur(coins, n, amount, dp);
    }
    
    int recur(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(ind == 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notpick = recur(coins, ind-1, amount, dp);
       
        int pick = 0;
        if(coins[ind-1] <= amount)
        pick = recur(coins, ind, amount - coins[ind-1], dp);

        dp[ind][amount] =  pick + notpick;
        return dp[ind][amount];
    }
};