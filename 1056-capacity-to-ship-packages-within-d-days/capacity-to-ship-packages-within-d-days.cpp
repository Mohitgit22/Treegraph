class Solution {
public: 
    bool isValid(vector<int>& weights, int mid, int k) {
        int cnt= 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];

            if(sum > mid){
                sum = weights[i];
                cnt++;
            }
        }
        return (cnt <= k);
    }

    int bs(vector<int>& weights, int l, int r, int k){
        int res = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(weights, mid, k)){
                res= min(res, mid);
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }
        return (res == INT_MAX ? -1 : res);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        return bs(weights, maxi, sum, days);
    }
};