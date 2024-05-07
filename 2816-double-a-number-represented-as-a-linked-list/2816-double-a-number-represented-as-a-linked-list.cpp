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
    ListNode* reverse(ListNode * head){
        ListNode* prev=NULL,*curr=head,*forword=NULL;
        while(curr!=NULL){
            forword=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forword;
        }
        return prev;
    }
    ListNode* Double(ListNode * head){
        int rem=0;
        ListNode* temp=head,*temp2=NULL;
        while(temp!=NULL){
            int val=2*temp->val;
            val+=rem;
            int x=val%10;
            rem=val/10;
            temp->val=x;
            temp2=temp;
            temp=temp->next;
        }
        ListNode* newNode=new ListNode(rem);
        if(rem!=0){
            temp2->next=newNode;
        }
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode * t=reverse(head);
        head=t;
        t=Double(head);
        return reverse(t);
    }
};