class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int res =  recur(coins, n-1, amount, dp);

        if(res == 1e9) return -1;
        return res;
    }

    int recur(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp){
       if(ind == 0){
        if(amount % coins[ind] == 0)
        return amount/coins[ind];
        else
        return 1e9;
       }
    
      if(dp[ind][amount] != -1) return dp[ind][amount];

       int pick = 1e9;
       if(coins[ind] <= amount){
        pick = 1 + recur(coins, ind, amount - coins[ind], dp);
       }
       int nopick = recur(coins, ind-1, amount, dp);
        
       dp[ind][amount] = min(pick, nopick);
       return dp[ind][amount];
    }
};