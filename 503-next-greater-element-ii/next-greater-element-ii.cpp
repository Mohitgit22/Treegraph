class Solution {
public:
    void ngr(vector<int>& arr, vector<int>& res){
     stack<int> st;
    int n = arr.size();
     for(int i = n-1; i>=0; i--){

        while(!st.empty() and st.top() <= arr[i]) st.pop();

        res[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
     }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        
        for(auto it: nums){
            arr.push_back(it);
        }
        vector<int> res(arr.size());
        ngr(arr, res);
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            ans.push_back(res[i]);
        }
        return ans;
    }
};