class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for(int i = n-1; i> 0; i--){
            if(nums[i] > nums[i-1]){
                int ind = i-1;
                 flag = true;
                for(int j = n-1; j > ind; j--){
                    if(nums[j] > nums[ind]){
                        swap(nums[j], nums[ind]);
                       
                        break;
                    }
                }
                reverse(nums.begin() + ind+ 1, nums.end());
                // sort(nums.begin() + ind + 1, nums.end());
                break;
            }
        }

        if(!flag)
        reverse(nums.begin(), nums.end());
    }
};