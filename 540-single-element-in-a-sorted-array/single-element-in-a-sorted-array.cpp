class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};