class Solution {
public:
    bool check(vector<int>& nums) {
        int pvt = 0;
        int n = nums.size();
        int cnt= 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
            cnt++;
            pvt = i+1;
            }

            if(cnt> 1) return false;
        }
        // Check if left part (from pvt to end) is sorted
        for(int i = pvt; i < n - 1; i++){
            if(nums[i] > nums[i + 1])
                return false;
        }
        
        // // Check if right part (from start to pvt-1) is sorted
        for(int i = 0; i < pvt - 1; i++){
            if(nums[i] > nums[i + 1])
                return false;
        }
        
        // // Check if rotation is valid (last element <= first element)
        if(pvt > 0 && nums[n - 1] > nums[0])
            return false;
            
        return true;
    }
};
