class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, len = 0, maxlen = INT_MIN;
        while(r < n){
             if(nums[r] == 0)
             cnt++;

             while(cnt > k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }

            if( cnt <= k){
                len = r-l+1;
                maxlen = max(len, maxlen);
            }
          r++;
        }
        return maxlen;
    }
};