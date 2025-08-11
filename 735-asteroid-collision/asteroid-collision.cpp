class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

    for(int &it : asteroids){

        while(!st.empty() and st.top() > 0 and it < 0){

            int sum = st.top() + it;

            if(sum > 0){
                it = 0;
            }else if(sum == 0){
                it = 0;
                st.pop();
            }else
               st.pop();
        }

        if(it!=0) st.push(it);
    }

        vector<int> res;

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};