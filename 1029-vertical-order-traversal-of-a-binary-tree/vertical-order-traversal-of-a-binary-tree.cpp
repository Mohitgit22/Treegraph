class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<pair<int, int>>> mp;  // column -> list of (row, val)
        queue<pair<TreeNode* , pair<int, int>>> que;
        que.push({root, {0, 0}});

        while(!que.empty()){
            auto [node, temp] = que.front();
            auto [row, col] = temp;
            que.pop();

            mp[col].push_back({row, node->val});

            if(node->left)
                que.push({node->left, {row+1, col-1}});
            if(node->right)
                que.push({node->right, {row+1, col+1}});
        }

        vector<vector<int>> ans;
        for(auto &[col, vec] : mp){
            // sort by row, then val
            sort(vec.begin(), vec.end());
            vector<int> colVals;
            for(auto &[row, val] : vec){
                colVals.push_back(val);
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};
