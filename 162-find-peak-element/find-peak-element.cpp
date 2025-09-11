class Solution {
public:
    int bs(int l, int r, vector<int>& nums){
       int n = nums.size()-1;

       while(l <= r){
        int mid = l + (r-l)/2;
       
         if(mid == 0 and nums[mid] > nums[mid+1])
        return mid;

        if(mid == n and nums[mid] > nums[mid-1])
        return mid;

        if(mid > 0 and nums[mid] > nums[mid-1] and mid < n and nums[mid] > nums[mid+1])
        return mid;

      

        if(mid-1 >= 0 and nums[mid-1] > nums[mid])
        r = mid-1;
        else if(mid + 1 <= n and nums[mid+1] > nums[mid])
        l = mid + 1;
       }
      return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums.size() == 1) return 0;

        return bs(l, r, nums);
    }
};