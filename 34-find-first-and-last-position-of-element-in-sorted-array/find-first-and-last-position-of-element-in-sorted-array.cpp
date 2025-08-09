class Solution {
public:
    int first_el_idx(vector<int>& nums, int t){
     int n = nums.size();
     int l = 0, r = n-1;
     int ans = -1;
     while(l <= r){
        int mid = l + (r-l)/2;
        if(nums[mid] == t){
          ans = mid;
          r = mid - 1;
        }else if(nums[mid] > t)
        r = mid-1;
        else
        l = mid + 1;
     }
     return ans;
    }

    int second_el_idx(vector<int>& nums, int t){
     int n = nums.size();
     int l = 0, r = n-1;
     int ans = -1;
     while(l <= r){
        int mid = l + (r-l)/2;
        if(nums[mid] == t){
          ans = mid;
          l = mid + 1;
        }else if(nums[mid] > t)
        r = mid-1;
        else
        l = mid + 1;
     }
     return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_el_idx(nums, target);
        int second = second_el_idx(nums, target);
        return {first, second};
    }

};