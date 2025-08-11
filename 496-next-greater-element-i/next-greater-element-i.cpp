class Solution {
public:
    void ngr(vector<int>& nums2, map<int, int>& mp){
        int n = nums2.size();
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
         
        while(!st.empty() and st.top() < nums2[i]) st.pop();

        mp[nums2[i]] = st.empty() ? -1 : st.top();

        st.push(nums2[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mp;
        ngr(nums2, mp);

        for(auto it : nums1){
            if(mp.find(it)!= mp.end()){
                res.push_back(mp[it]);
            }else
            res.push_back(-1);
        }
        return res;
    }
};