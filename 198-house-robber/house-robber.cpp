class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,  -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i =2; i < n+1; i++) {
           int pick = nums[i-1] + dp[i-2];
           int notpick = dp[i-1];
           dp[i] = max(pick, notpick);
        }
        return dp[n];
    }

    // int recur(int n, vector<int>& nums, vector<int>& dp){
    //     if(n < 0){
    //     return 0;
    //     }

    // if(n==0)
    // return nums[n];
       
    //     if(dp[n] != -1) return dp[n];
       
    //     int pick = nums[n] + recur(n-2, nums, dp);
    //     int notpick = recur(n-1, nums, dp);

    //     dp[n] = max(pick, notpick);
    //     return dp[n];
    // }
};