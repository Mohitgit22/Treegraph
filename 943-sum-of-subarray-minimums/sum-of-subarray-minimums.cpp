class Solution {
public:
   const int MOD = 1e9 + 7;

    void nsr_idx(vector<int>& arr, vector<int>& nsr) {
    stack<int> st;
    int n = arr.size();
    for(int i = n-1; i >= 0; i--){

        while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();

        int el = st.empty() ? n : st.top();

        nsr.push_back(el);

        st.push(i);
    }
    reverse(nsr.begin(), nsr.end());
    }

    void nsl_idx(vector<int>& arr, vector<int>& nsl) {
    stack<int> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){

        while(!st.empty() and arr[st.top()] > arr[i]) st.pop();

        int el = st.empty() ? -1 : st.top();

        nsl.push_back(el);

        st.push(i);
    }
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nsr, nsl;
        nsr_idx(arr, nsr);
        nsl_idx(arr, nsl);

        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            int left = i - nsl[i];
            int right = nsr[i] - i;
            long long contribution = (1ll*arr[i] * ((left * right) % MOD)) % MOD;

            sum = (sum + contribution) % MOD;
        }
        return sum;
    }
};