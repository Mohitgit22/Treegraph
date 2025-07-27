class Solution {
public:
    int findsum(vector<int>& nums, int val){
        int sum = 0;
        for(auto it: nums){
            sum += ceil((double)it / val);

        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;
            int res = findsum(nums, mid);
            cout<<"mid : "<<mid<<" res : "<<res<<endl;
            if(res > threshold)
            l = mid + 1;
            else if(res <= threshold){
                ans = min(ans, mid);
                r = mid - 1;
            }
        }
        return ans;
    }
};