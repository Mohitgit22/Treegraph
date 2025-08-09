class Solution {
public:
    int findpvt(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
            l = mid+1;
            else
            r = mid;
        }
        return l;
    }
    int findMin(vector<int>& nums) {
        int pvt = findpvt(nums);

        return nums[pvt];
    }
};