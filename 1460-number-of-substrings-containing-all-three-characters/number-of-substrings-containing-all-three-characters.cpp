class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0, r = 0;
        map<char, int> mp;
       
        int res = 0;
        while(r < n) {
          mp[s[r]]++;

          while(mp['a'] > 0 and mp['b'] > 0 and mp['c'] > 0){
          res += (n-r);

          mp[s[l]]--;
          l++;
        
        //   r++;
        //   mp[s[r]]++;
          }
         r++;
        }

        return res;
    }
};