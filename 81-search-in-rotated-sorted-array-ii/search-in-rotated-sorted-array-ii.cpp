class Solution {
public:

    int pivot(vector<int>& nums){
      int l = 0;
      int r = nums.size() -1;

      while(l < r){
        while(l < r and nums[l] == nums[l+1])
        l++;
        while( l < r and nums[r] == nums[r-1])
        r--;

        int mid = l + (r-l)/2;

        if(nums[mid] > nums[r])
        l = mid + 1;
        else if(nums[mid] < nums[r])
        r = mid;
      }
      return l;
    }

    bool search(int l, int r, vector<int>& nums, int target){
       while(l <= r ){
          int mid = l + (r -l)/2;

          if(nums[mid] == target) return true;
          else if(nums[mid] > target) 
          r = mid-1;
          else
          l = mid + 1;
       }
       return false;
    }

    bool search(vector<int>& nums, int target) {
        int pvt = pivot(nums);
        return search(0, pvt-1, nums, target) ||  search(pvt, nums.size()-1, nums, target);
    }
};