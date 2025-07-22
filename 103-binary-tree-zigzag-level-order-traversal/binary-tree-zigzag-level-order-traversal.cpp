/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> que;
        que.push(root);

        int cnt = 0;
        vector<vector<int>> ans;
        
        while(!que.empty()) {
            int size = que.size();
            vector<int> currlvl_nodes;
            for(int i = 0; i < size; i++){
                 auto curr = que.front();
                 que.pop();

                 currlvl_nodes.push_back(curr->val);

                 if(curr->left)
                 que.push(curr->left);
                 if(curr->right)
                 que.push(curr->right);
            }
            if(cnt % 2 == 0)
            ans.push_back(currlvl_nodes);
            else{
                reverse(currlvl_nodes.begin(), currlvl_nodes.end());
                 ans.push_back(currlvl_nodes);
            }
            cnt++;
        }
        return ans;
    }
};