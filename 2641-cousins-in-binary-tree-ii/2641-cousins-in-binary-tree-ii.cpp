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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int sum1=0,sum2=0;
        queue<TreeNode*>q;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            int n=q.size();
            int size=0;
            while(n--){
                auto x=q.front();
                q.pop();
                x->val=sum1-x->val;
                int sib=(x->left!=NULL)?x->left->val:0;
                sib+=(x->right!=NULL)?x->right->val:0;
                if(x->left!=NULL){
                    q.push(x->left);
                    sum2+=x->left->val;
                    x->left->val=sib;
                }
                if(x->right!=NULL){
                    q.push(x->right);
                    sum2+=x->right->val;
                    x->right->val=sib;
                }
            }
            sum1=sum2;
            sum2=0;
        }
        return root;
    }
};