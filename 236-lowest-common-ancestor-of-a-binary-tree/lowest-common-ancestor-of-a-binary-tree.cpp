/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* ans = nullptr;

   bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
       if(root == nullptr)
        return false;
      
       bool currnodeisLCA = (root == p || root ==  q);
       bool left = helper(root->left, p, q);
       bool right =  helper(root->right, p, q);
       
       if((currnodeisLCA && left) ||(currnodeisLCA && right) || (left && right))
       ans = root;

       return currnodeisLCA || left || right;
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         helper(root, p, q);
         return ans;
    }
};