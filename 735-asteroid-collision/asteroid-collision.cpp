class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty() and asteroids[i] < 0){
            st.push(asteroids[i]);
            continue;
            }

        
          
         
           //correct
            while(!st.empty() and asteroids[i] < 0 and st.top() > 0 and abs(asteroids[i]) > st.top()){
            st.pop();
            }
              //correct
            if(!st.empty() and asteroids[i] < 0 and abs(asteroids[i]) == st.top()){
                st.pop();
                continue;
            }
            //correct
            if(!st.empty() and asteroids[i] < 0 and abs(asteroids[i]) < st.top())
            continue; 
            
        //    if(!st.empty() and ((asteroids[i] < 0 and st.top() < 0 )||(asteroids[i] > 0 and st.top() > 0 ))){
                st.push(asteroids[i]);
            //     continue;
            // }
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