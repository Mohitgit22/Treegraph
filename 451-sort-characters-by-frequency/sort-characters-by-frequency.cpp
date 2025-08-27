class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;

        map<char, int> mp;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});
        }
       
        string ans = "";
        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();

            int freq = p.first;
            char ch = p.second;

            while(freq > 0){
               ans += ch;
               freq--;
            }
        }
        return ans;
    }
};