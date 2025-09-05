class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++){
           int curr = asteroids[i];
            while(!st.empty() and st.top() > 0 and curr < 0){
               int sum = st.top() + curr;

               if(sum > 0){
                curr = 0;
               }else if(sum < 0){
                st.pop();
               }else{
                st.pop();
                curr = 0;
               }
            }

        if(curr != 0)
           st.push(curr);
        }

        vector<int> ans;
        while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};