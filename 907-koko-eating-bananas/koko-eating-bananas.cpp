class Solution {
public:
     int bs(int l, int r, vector<int>&piles, int h ){
        
        int minspeed = INT_MAX;
        while(l <= r){
        int mid = l + (r-l)/2;
        long long sum = 0;


        for(int it : piles){
            sum += ceil((double)it / mid);
        }
        if(sum <= h and mid < minspeed){
            minspeed = mid;
            // minsum=sum;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
        }
        if(minspeed == INT_MAX) return r;
        return minspeed;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        return bs(1, maxi, piles, h);
    }
};