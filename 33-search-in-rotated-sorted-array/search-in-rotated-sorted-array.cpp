class Solution {
public:
    int findpvt(vector<int>& nums){
        int l = 0;
        int r = nums.size()-1;
      
        int mid = -1;
        while( l < r){
            mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) 
            l = mid + 1;
            else
            r = mid;
        }
        return l;
    }

    int search(int l, int r, int t, vector<int>& nums) {
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
        int pivot = findpvt(nums);
        cout<<pivot<<"is"<<endl;
        int n = nums.size();

        int el = search(0, pivot-1, target, nums);

        int el2 = search(pivot, n-1, target, nums);
        
        return max(el, el2);
    }
};