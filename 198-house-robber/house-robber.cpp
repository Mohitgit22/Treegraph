class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recur(n-1, nums, dp);
    }

    int recur(int n, vector<int>& nums, vector<int>& dp){
        if(n < 0){
        return 0;
        }
       
        if(dp[n] != -1) return dp[n];
       
        int pick = nums[n] + recur(n-2, nums, dp);
        int notpick = recur(n-1, nums, dp);

        dp[n] = max(pick, notpick);
        return dp[n];
    }
};