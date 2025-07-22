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
    int height(TreeNode* root){
        if(root == nullptr)
        return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    bool check(TreeNode* root){
        if(!root) 
        return true;

        int lh = 0, rh = 0;
        if(root->left)  lh = height(root->left);
        if(root->right)  rh = height(root->right);
        if(abs(lh - rh) >= 2) return false;

        return check(root->left) and  check(root->right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        return true; 

        return check(root);
    }
};