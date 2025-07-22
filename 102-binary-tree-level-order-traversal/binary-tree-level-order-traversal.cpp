class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> curr_lvl_nodes;


        while (!que.empty()) {
            int size = que.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();

                curr_lvl_nodes.push_back(curr->val);

                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }

            ans.push_back(curr_lvl_nodes);
            curr_lvl_nodes.clear();

        }

        return ans;
    }
};
