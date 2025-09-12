class Solution {
public:
    bool isValid(vector<int>& bloomDay, int mid, int m, int k){
         int cnt_of_banquet = 0;
         int curr_cnt = 0;

    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= mid){
            curr_cnt++;
            if(curr_cnt == k){
                cnt_of_banquet++;
                curr_cnt = 0;
            }
        } else {
            curr_cnt = 0;
        }
    }
    return cnt_of_banquet >= m;
    }
    int bs(vector<int>& bloomDay, int l, int r, int m, int k){
         int res = INT_MAX;

         while(l <= r){
            int mid = l + (r-l)/2;

            if(isValid(bloomDay, mid, m, k)){
                res = min(res, mid);
                r = mid -1 ;
            }else
            l = mid + 1;
         }

         return (res == INT_MAX ? -1 : res); 
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // int n = bloomDay.size();
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        return bs(bloomDay, mini, maxi, m, k);
    }
};