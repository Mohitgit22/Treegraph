class Solution {
public:
    int lowerb_index(vector<int>& nums, int t) {
       int n = nums.size();
       int l = 0, r = n - 1;
       int res = INT_MAX;
       while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == t) return mid;
        else if(nums[mid] > t){
            res = mid;
            r = mid-1;
        }else{
            l = mid + 1;
        }
       }

       return (res == INT_MAX) ? n : res;
    }
    int searchInsert(vector<int>& nums, int target) {

     //Step -> Only find the lower bound index
     return lowerb_index(nums, target);
    }
};