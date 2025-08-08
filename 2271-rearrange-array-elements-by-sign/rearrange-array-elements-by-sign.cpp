class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        
        // Step 1: Separate positive and negative numbers
        for(int num : nums) {
            if(num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }
        
        vector<int> result;
        int i = 0, j = 0;
        
        // Step 2: Interleave pos and neg
        while(i < pos.size() && j < neg.size()) {
            result.push_back(pos[i++]);
            result.push_back(neg[j++]);
        }
        
        return result;
    }
};
