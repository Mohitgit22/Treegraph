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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
  
        vector<int> ans;
        while(!que.empty()){
            int sz = que.size();

            for(int i = 0; i < sz; i++){
                TreeNode* p = que.front();
                que.pop();

                if(i == sz-1)
                ans.push_back(p->val);

                if(p->left)
                que.push(p->left);
                if(p->right)
                que.push(p->right);
            }
        }
        return ans;
    }
};