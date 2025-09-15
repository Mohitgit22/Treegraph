class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
         
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1)); 
        return recur(word1, word2, n1, n2, dp);
    }

    int recur(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind1 == 0) return ind2 ;  // If s1 is exhausted, insert remaining s2 characters
        if(ind2 == 0) return ind1 ;  // If s2 is exhausted, delete remaining s1 characters
       
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int mini1, mini2;
        if(s1[ind1-1] == s2[ind2-1]){
            dp[ind1][ind2] =  recur(s1, s2, ind1-1, ind2-1, dp);
        }
        else{
            int insertOp = 1 + recur(s1, s2, ind1, ind2 - 1, dp);   // Insert character
            int deleteOp = 1 + recur(s1, s2, ind1 - 1, ind2, dp);   // Delete character
            int replaceOp = 1 + recur(s1, s2, ind1 - 1, ind2 - 1, dp); // Replace character
            dp[ind1][ind2] =  min({insertOp, deleteOp, replaceOp});
        }
        return dp[ind1][ind2];
    }
};