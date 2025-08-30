class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1)
        return s.length();

       map<char, int> mp;
       int st = 0;

       int len = INT_MIN;
       for(int i = 0; i < s.length(); i++) {
        
          int idx = (mp.find(s[i]) != mp.end() ? mp[s[i]] : -1);

          if(idx != -1 and idx >= st){
           len = max(len, i - st );
           st = idx + 1;
          }

          mp[s[i]] = i;
       }

       // Final update for the last window
        len = max(len, (int)s.length() - st);

        return len;
    }
};