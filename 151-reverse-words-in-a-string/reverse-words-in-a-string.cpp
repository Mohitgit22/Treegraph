class Solution {
public:
    string reverseWords(string s) {
       vector<string> vec;
       string word = "";
        for(int i = 0; i < s.length(); i++) {
           if(s[i] != ' ' ){
            word += s[i];
           }else{
                if(word.length() != 0){
                   vec.push_back(word);
                   word = "";
                }
            }
        }
        if (!word.empty()) vec.push_back(word); // last word
        string ans= "";

        for(int i = vec.size()-1; i>= 0; i--){
            ans+=vec[i];
            if(i!= 0) ans += " ";
        }
        return ans;
    }
};