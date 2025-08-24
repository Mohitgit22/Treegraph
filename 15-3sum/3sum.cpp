class Solution {
public:
    vector<vector<int>> twosum(vector<int>& nums, int st, int end, int target ){
        map<int, int> mp;

        int sum = 0;
        vector<vector<int>> ans;
        for(int i = st; i < end; i++){
          int el = nums[i];
          int remain = target - el;

          if(mp.find(remain) != mp.end()){
             ans.push_back({remain, el});
          }
          mp[el] = i;
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n-1; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // <-- skip duplicate first element
            int el = nums[i];
            
            int req_sum = 0-(el);
            int left = i+1, right = n-1;
            
            while(left < right){

                if(nums[left] + nums[right] == req_sum){
                    ans.push_back({el, nums[left], nums[right]});
                
               
               //check for duplicates by shofting
               while(left < right and nums[left] == nums[left + 1])
               left++;
               while(left < right and nums[right] == nums[right - 1])
               right--;

               left++;
               right--;

                }
               else if(nums[left] + nums[right] > req_sum)
                right--;
                else 
                left++;
            }  
        }
         return ans;
    }
};