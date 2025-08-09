class Solution {
public:
    int findpvt(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else
             r = mid;
        }
        return l;
    }

    int search(vector<int>& nums, int start, int end, int t){
        int l =start, r = end;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] > t)
            r = mid-1;
            else
            l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pvt = findpvt(nums);
        int n = nums.size();

        int el1 = search(nums, 0, pvt-1, target);
        int el2 = search(nums, pvt, n-1, target);
        return max(el1, el2);
    }
};