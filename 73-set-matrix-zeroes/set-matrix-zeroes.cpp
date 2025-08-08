class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
       
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(rows.find(i) != rows.end() || columns.find(j) != columns.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};