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
    TreeNode* f(TreeNode* root, int t){
         if (!root) {
            
            return NULL;
        }

        
        root->left = f(root->left, t);
        
        root->right = f(root->right, t);

        
        if (!root->left && !root->right && root->val == t) {
           
            return NULL;
        }

      
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root,target);
    }
};