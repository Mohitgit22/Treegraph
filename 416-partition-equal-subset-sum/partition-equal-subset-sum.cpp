class Solution {
public:
    bool recur(vector<int>&nums, int target, int ind, int cur_sum, vector<vector<int>>& dp){
        if(nums[ind] + cur_sum == target) return true;

        if(ind == 0){
            if(nums[ind] + cur_sum == target) return true;
            else
            return false;
        }
        
        if(dp[ind][cur_sum] != -1) return dp[ind][cur_sum];

        bool pick = false;
        if(nums[ind] + cur_sum <= target)
        pick = recur(nums, target, ind-1, cur_sum + nums[ind], dp);
        
        bool notpick = recur(nums, target, ind-1, cur_sum, dp);

        dp[ind][cur_sum] = pick || notpick;
        return dp[ind][cur_sum];
    }


    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
     
        if(sum % 2 != 0) return false;

        sum  = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

        return recur(nums, sum, n-1, 0, dp );
    }
};