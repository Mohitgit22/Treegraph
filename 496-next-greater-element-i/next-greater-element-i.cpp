class Solution {
public:
    void ngr(vector<int>& nums2, int n, map<int , int> &mp){
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
          while(!st.empty() and st.top() <= nums2[i]){
            st.pop();
          }

          int x = st.empty() ? -1 : st.top();
          mp[nums2[i]] = x;

          st.push(nums2[i]);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int, int> mp;
        ngr(nums2, n, mp);
       
        vector<int> ans;
        for(int it : nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};