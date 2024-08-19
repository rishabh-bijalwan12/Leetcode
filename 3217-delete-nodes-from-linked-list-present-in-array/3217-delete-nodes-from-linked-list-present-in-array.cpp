/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto x:nums)st.insert(x);
        ListNode* temp=head,*prev=head;
        while(st.find(temp->val)!=st.end()){
            temp=temp->next;
        }
        head=temp;
        prev=head;
        temp=head->next;
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return head;
    }
};