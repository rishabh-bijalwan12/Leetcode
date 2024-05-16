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
    bool f(TreeNode* root){
        if(root->left==NULL && root->right==NULL )return root->val==1;
        bool x=0,y=0;
        if(root->val==3){
            x=f(root->left);
            y=f(root->right);
            return x&&y;
        }
        else{
            x=f(root->left);
            y=f(root->right);
            return x||y;
        }
    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};