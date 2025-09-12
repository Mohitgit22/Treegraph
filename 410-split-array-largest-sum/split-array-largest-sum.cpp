class Solution {
public:
    bool isValid(vector<int>&nums, int mid, int k){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
          sum += nums[i];
          if(sum > mid){
            sum = nums[i];
            cnt++;
          }
        }
        return (cnt <= k);
    }

    int bs(vector<int>& nums, int l, int r, int k){
         int res = INT_MAX;

         while(l <= r){
            int mid = l + (r-l)/2;

            if(isValid(nums, mid, k)){
                res = min(res, mid);
                r = mid-1;
            }else
                l = mid + 1;
         }

         return res == INT_MAX ? -1 : res;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return bs(nums, mini, sum, k);
    }
};