class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int first = nums[0];
        int sec = nums[0];

        if(nums.size() == 2){
            if(nums[0] == nums[1]) return {nums[0]};
            else
            return nums;
        }
        

        int fc = 1;
        int sc = 0;

        for(int i = 1; i < nums.size(); i++){
            if(first == nums[i]){
                first = nums[i];
                fc++;
            }else if(sec == nums[i]){
                sec = nums[i];
                sc++;
            }else if(fc == 0){
                first = nums[i];
                fc = 1;
            }else if(sc == 0){
                sec = nums[i];
                sc = 1;
            }else{
                fc--;
                sc--;
            }
        }

        fc = 0, sc = 0;
        for(int it : nums){
            if(it == first) fc++;
            else if(it == sec) sc++;
        }

        vector<int> ans;
        if(fc > nums.size()/3)
        ans.push_back(first);
        if(sc > nums.size()/3)
        ans.push_back(sec);
        return ans;

    }
};