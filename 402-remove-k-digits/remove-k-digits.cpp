class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i = 0; i < num.length(); i++) {
            while(!st.empty() and k > 0 and (st.top() - '0') > (num[i]- '0')){
                st.pop();
                k--;
            }
           st.push(num[i]);
        }

        while(k > 0){
        st.pop();
        k--;
        }

        if(st.empty()) 
        return "0";

        string res ="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        //remove the leading zeroes
        while(res.length() and res.back() == '0'){
            res.pop_back();
        }
         
        if(res.length() == 0) return "0";

        reverse(res.begin(), res.end());
        return res;
    }
};