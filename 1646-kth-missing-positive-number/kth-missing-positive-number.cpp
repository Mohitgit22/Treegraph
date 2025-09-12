class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1;
        int r = arr.back() + k;  // upper bound

        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            // Count how many numbers are missing until mid
            int missing = mid - (upper_bound(arr.begin(), arr.end(), mid) - arr.begin());
            
            if(missing < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l;
    }
};
