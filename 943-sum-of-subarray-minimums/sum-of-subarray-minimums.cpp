class Solution {
public:
  const int MOD = 1e9 + 7;
  vector<int>  NSR(vector<int>& arr, int n){
        stack<int> st;
       vector<int> res(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                st.pop();
            }

            int x = st.empty() ? n : st.top();
            res[i] = x;
            st.push(i);
        }
        return res;
    }

    vector<int> NSL(vector<int>& arr, int n){
        stack<int> st;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]){
                st.pop();
            }

            int x = st.empty() ? -1 : st.top();

            res[i] = x;
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int>nsr = NSR(arr, n);
        vector<int> nsl = NSL(arr, n);

         vector<int> left(n), right(n), contribution(n);
        for(int i = 0; i < n; i++){
         left[i]  = i - nsl[i];
         right[i] = nsr[i] - i;
         contribution[i] = ((((1LL * left[i] * right[i]) % MOD) * arr[i]) % MOD);
        }
        

        int sum = 0;
        for(int it: contribution){
            sum += it;
            sum = sum % MOD;
        }
        sum = sum % MOD;
        return sum;
    }
};