class Solution {
public:
    bool bs(vector<int> v, int t){
        int l = 0, r = v.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] == t) return true;
            else if(v[mid] > t)
            r = mid-1;
            else
            l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> vec;
        int m = matrix.size();
        
        for(int i = 0; i < m; i++){
            vec.push_back(matrix[i][0]);
        }

        auto it = upper_bound(vec.begin(), vec.end(), target);
        int row = it - vec.begin() -1;
        // cout<<row;
        if(row < 0) return false;

        return bs(matrix[row], target);
    }
};