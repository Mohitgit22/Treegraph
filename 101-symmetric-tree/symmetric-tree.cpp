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
    bool pal(TreeNode* p, TreeNode* q){
        if(p == nullptr and q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;

        return pal(p->left, q->right) and pal(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr || (!root->left and !root->right))
        return true;

        return pal(root->left, root->right);
    }
};