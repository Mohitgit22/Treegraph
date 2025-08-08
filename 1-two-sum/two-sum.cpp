class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> mp;

        int first = 0;
        int second = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
         int el = nums[i];
         
         int left = target-el;
         if(mp.find(left) != mp.end()){
            first = mp[left];
            second = i;
            return {first, second};
         }

         mp[el] = i;
        }
        return {-1, -1};
    }
};