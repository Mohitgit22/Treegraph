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
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0)
                dp[i][j] = false;

                if(j == 0)
                dp[i][j] = true;
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(nums[i-1] <= j )
                  dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                else
                  dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
};