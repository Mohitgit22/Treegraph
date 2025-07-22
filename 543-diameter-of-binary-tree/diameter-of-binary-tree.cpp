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
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Update diameter at current node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        
        maxDiameter = 0;
        height(root);
        return maxDiameter;
    }
};