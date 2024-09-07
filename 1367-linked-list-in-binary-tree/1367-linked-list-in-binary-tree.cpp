class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;

        if (root->val == head->val) {
            if (solve(head->next, root->left) || solve(head->next, root->right)) {
                return true;
            }
        }

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)return 0;
        return solve(head, root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
