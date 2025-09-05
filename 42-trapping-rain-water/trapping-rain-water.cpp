class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        leftmax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        rightmax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }

         //calucalte water above each building 
         vector<int> vec(n);
        for(int i = 0; i < n; i++){
            vec[i] = min(leftmax[i], rightmax[i]) - height[i];
        }
          //find total sum
          int sum = 0;
        for(int it : vec){
            sum += it;
        }
        return sum;
    }
};