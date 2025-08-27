// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.length() > haystack.length()) return -1;
//         if(needle.empty()) return 0;
        
//         int j = 0;
//         int ind = -1;
//         string word = "";
//         for(int i = 0; i < haystack.length(); i++) {

//            if(haystack[i] == needle[j]){
//              if(ind == -1) ind = i;
//              word += needle[j];
//              if(word == needle) return ind;
//              j++;
//                  if (ind != -1) {
//                     // backtrack: next iteration should start at ind+1
//                     i = ind;
//                 }
//                 word = "";
//                 j = 0;
//                 ind = -1;
//             }
//         }
//         return ind;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        if (needle.empty()) return 0;

        int j = 0;        // index in needle
        int ind = -1;     // start index of match

        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[j]) {
                if (ind == -1) ind = i;      // mark start
                if (++j == needle.length())  // full match found
                    return ind;
            } else {
                if (ind != -1) {
                    // backtrack to try starting at next position
                    i = ind;
                }
                // reset state
                j = 0;
                ind = -1;
            }
        }
        return -1; // no match found
    }
};
