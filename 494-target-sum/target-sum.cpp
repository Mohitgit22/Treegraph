class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int total = sum + target;
        
        // Check if partition is possible
        if(total % 2 != 0)
            return 0;
            
        int subsetsum = total / 2;
        int n = nums.size();

        if(subsetsum < 0) return 0;
        
        // Memoization table: dp[i][sum] = -1 (not computed), otherwise stores result
        vector<vector<int>> dp(n+1, vector<int>(subsetsum+1, 0));
        
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 1;
        }
        
        
        for(int i = 1; i < n+1; i++){
            for(int j = 0 ; j < subsetsum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][subsetsum];
    }
};