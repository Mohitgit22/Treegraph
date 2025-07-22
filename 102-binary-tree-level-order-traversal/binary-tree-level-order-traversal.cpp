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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        // if(!root->left and !root->right) return {{root->val}};
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
     
       vector<int> curr_lvl_nodes;
        while(!que.empty()){
            int size = que.size();

            for(int i = 0; i < size; i++){
            auto [curr, lvl] = que.front();
            que.pop();

            curr_lvl_nodes.push_back(curr->val);

            if(curr->left){
                que.push({curr->left, lvl+1});
            }
            if(curr->right){
                que.push({curr->right, lvl+1});
            }
         }

         ans.push_back(curr_lvl_nodes);
         curr_lvl_nodes.clear();
        }
        return ans;
    }
};