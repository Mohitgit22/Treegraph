class Solution {
public:
    vector<int> lowerbound(vector<int>& nums, int t) {
        vector<int> res;
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == t){                
                int first_ind = mid;
                while(first_ind-1 >=0 and nums[first_ind-1] == t)
                first_ind--;

                int sec_ind = mid;
                while(sec_ind+1 < n and nums[sec_ind+1] == t)
                sec_ind++;
               
               res.push_back(first_ind);
               res.push_back(sec_ind);
               return res;
            }
            else if(nums[mid] > t){
                r = mid-1;
            }else
            l= mid + 1;
        }
       return {-1, -1};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return lowerbound(nums, target);
    }
};