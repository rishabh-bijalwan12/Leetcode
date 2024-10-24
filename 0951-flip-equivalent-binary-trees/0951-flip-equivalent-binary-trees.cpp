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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        if(root1->left==NULL && root2->left==NULL && root1->right==NULL && root2->right==NULL)return true;

        int l1=-1,l2=-1,r1=-1,r2=-1;
        if(root1->left!=NULL)
            l1=root1->left->val;
        if(root2->left!=NULL)
            l2=root2->left->val;
        if(root1->right!=NULL)
            r1=root1->right->val;
        if(root2->right!=NULL)
            r2=root2->right->val;
        
        if(l1==l2 && r1==r2){
            return solve(root1->left, root2->left)&&solve(root1->right, root2->right); 
        }
        else if(l1!=l2 && r1!=r2 && l1==r2 && l2==r1){
            TreeNode* t = root1->left;
            root1->left=root1->right;
            root1->right=t;
            return solve(root1->left, root2->left)&&solve(root1->right, root2->right);
        }
        else{
            return false;
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1!=NULL && root2!=NULL && root1->val != root2->val)return false;
        bool x=solve(root1,root2);
        return x;
    }
};