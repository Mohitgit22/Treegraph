class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num){

            while(!st.empty() and st.top() > ch and k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }
         
        if(st.empty())return "0";

        while( k> 0){
            st.pop();
            k--;
        }

        if(st.empty())
        return "0";

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        //remove the leading zeroes
        while(res.length() and res.back() == '0'){
            res.pop_back();
        }
        if(res.length() == 0)return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};