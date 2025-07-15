class Solution {
public:
    void PSE(vector<int>& heights, vector<int> &pse) {
        int n = heights.size();
        stack<int> st;

        for(int i = 0; i <= n-1; i++) {
        while(!st.empty() and heights[st.top()] > heights[i]){
            st.pop();
        }
        
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    }
    
    void NSE(vector<int>& heights, vector<int> &nse) {
        int n = heights.size();
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
        while(!st.empty() and heights[st.top()] >= heights[i]){
            st.pop();
        }
        
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n);
        vector<int> nse(n);

        PSE(heights, pse);
        NSE(heights, nse);
       
       int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
           int length = nse[i] - pse[i] - 1;

           maxi = max(maxi, length*heights[i]);
        }
        return maxi;
    }
};