class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
        int res = recur(coins, n, amount, dp);

        return res == 1e9 ? -1 : res;
    }
    
    int recur(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        if(ind == 0) return 1e9;

       if(dp[ind][amount] != -1) return dp[ind][amount];

        int notpick = recur(coins, ind-1, amount, dp);
        
        int pick = 1e9;
        if(coins[ind-1] <= amount){
            pick = min(pick, 1 + recur(coins, ind, amount-coins[ind-1], dp));
        }
        dp[ind][amount] = min(pick, notpick);
        return dp[ind][amount];
    }
};