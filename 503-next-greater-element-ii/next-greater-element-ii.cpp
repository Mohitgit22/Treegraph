class Solution {
public:
    vector<int> ngr(vector<int>& arr){
        int n = arr.size();
        stack<int> st; 
        
        vector<int> ans(n);
        for(int i = n-1; i>= 0; i--) {
            while(!st.empty() and st.top() <= arr[i]){
                st.pop();
            }

            int x = st.empty() ? -1 : st.top();

            ans[i] = x;
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(2*n);

        for(int i = 0; i < 2*n; i++){
            arr[i] = nums[i%n];
        }
        
        vector<int> ans = ngr(arr);
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};