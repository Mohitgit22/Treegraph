class Solution {
public:

      const int MOD = 1e9 + 7;

    void nsr_idx(vector<int>& nums, vector<int>& nsr) {
    stack<int> st;
    int n = nums.size();
    for(int i = n-1; i >= 0; i--){

        while(!st.empty() and nums[st.top()] >= nums[i]) st.pop();

        int el = st.empty() ? n : st.top();

        nsr.push_back(el);

        st.push(i);
    }
    reverse(nsr.begin(), nsr.end());
    }

    void nsl_idx(vector<int>& nums, vector<int>& nsl) {
    stack<int> st;
    int n = nums.size();
    for(int i = 0; i < n; i++){

        while(!st.empty() and nums[st.top()] > nums[i]) st.pop();

        int el = st.empty() ? -1 : st.top();

        nsl.push_back(el);

        st.push(i);
    }
    }

    void ngl_idx(vector<int>& nums, vector<int>& ngl) {
    stack<int> st;
    int n = nums.size();
    for(int i = 0; i < n; i++){

        while(!st.empty() and nums[st.top()] < nums[i]) st.pop();

        int el = st.empty() ? -1 : st.top();

        ngl.push_back(el);

        st.push(i);
    }
    }
   

    void ngr_idx(vector<int>& nums, vector<int>& ngr) {
    stack<int> st;
    int n = nums.size();
    for(int i = n-1; i >= 0; i--){

        while(!st.empty() and nums[st.top()] <= nums[i]) st.pop();

        int el = st.empty() ? n : st.top();

        ngr.push_back(el);

        st.push(i);
    }
    reverse(ngr.begin(), ngr.end());
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> ngl, ngr, nsl, nsr;
       
        nsr_idx(nums, nsr);
        nsl_idx(nums, nsl);
        ngr_idx(nums, ngr);
        ngl_idx(nums, ngl);

        long long min_sum = 0;
        long long max_sum = 0;

        for(int i = 0; i < nums.size(); i++){
            long long left_min = i - nsl[i];
            long long right_min = nsr[i] - i;

            long long left_max = i - ngl[i];
            long long right_max = ngr[i] - i;

    long long contribution_min = nums[i] * (left_min * right_min);
    long long contribution_max = nums[i] * (left_max * right_max);

            min_sum = (min_sum + contribution_min) ;
            max_sum = (max_sum + contribution_max) ;
        }

        return max_sum - min_sum;

    }
};