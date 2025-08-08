class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int maj_el = nums[0];

        for(int i = 1; i < nums.size(); i++){
             if(cnt == 0){
                cnt =1;
                maj_el = nums[i];
                continue;
            }

          if(nums[i] != maj_el){
            cnt--;
          }else
          cnt++;
        }
        return maj_el;
    }
};