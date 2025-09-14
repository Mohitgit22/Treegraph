class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
         // Code here
        int n1 = s1.length();
        int n2 = s2.length();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i = 1; i < n1+ 1; i++){
            for(int j = 1; j < n2 +1; j++){
                if( s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i = n1;
        int j = n2;
        string str = "";
        while(i > 0 and j > 0){
            if(s1[i-1] == s2[j-1]){
                str += s1[i-1];
                i--;
                j--;
            }else {
                if(dp[i-1][j] > dp[i][j-1]){
                    str+= s1[i-1];
                    i--;
                }else{
                    str += s2[j-1];
                    j--;
                }
            }
        }

        while(i > 0){
            str += s1[i-1];
            i--;
        }
         while(j > 0){
            str += s2[j-1];
            j--;
        }
        
        reverse(str.begin(), str.end());
        // cout<<str<<endl;
        return str;
    }
};