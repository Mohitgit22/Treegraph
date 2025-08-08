class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = -1;
        int global_maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            global_maxi = max(global_maxi, sum);
            if(sum < 0){
                sum = 0;
                continue;
            }
            maxi = max(maxi, sum);
        }
        if(maxi == -1) return global_maxi;

        return maxi;
    }
};