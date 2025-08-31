class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0, rightsum = 0, maxi = 0;

        for(int i = 0; i < k; i++){
          leftsum += cardPoints[i];
        }
        maxi = leftsum;

        int r = n-1;
        for(int i = k-1; i >= 0; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[r];
            r--;
            maxi = max(maxi, leftsum + rightsum);
        }
        return maxi;
    }
};