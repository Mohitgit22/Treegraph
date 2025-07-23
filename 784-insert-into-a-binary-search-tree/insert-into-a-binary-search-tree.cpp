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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }
        
        TreeNode* curr = nullptr, *temp = root;
        while(root){
            curr = root;
            if(root->val > val){
                root = root->left;
            }else
            root = root->right;
        }

        if(curr->val > val)
        curr->left = new TreeNode(val);
        else
        curr->right = new TreeNode(val); 

        return temp;
    }
};