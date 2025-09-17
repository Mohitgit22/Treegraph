class Solution {
public:
   bool bs(vector<int>& vec, int t){
    int l = 0, r = vec.size()-1;
     while(l <= r){
        int mid = l + (r-l)/2;
        if(vec[mid] == t) 
        return true;
        else if(vec[mid] > t) 
        r = mid-1;
        else
        l = mid+1;
     }
     return false;
   }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        vector<int> vec;
        
        if(n == 0 || matrix[0].size() == 0) return false;


        for(int i = 0; i < n; i++){
          vec.push_back(matrix[i][0]);
        }

        auto it = upper_bound(vec.begin(), vec.end(), target);
        int idx = it - vec.begin() - 1;
     
        // cout<<"idx is : "<<idx;
        if(idx < 0) return false;

        vec = matrix[idx];
        return bs(vec, target);
    }
};