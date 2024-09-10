class Solution {
public:
    ListNode* solve(ListNode* head){
        ListNode* t1=head,*t2=head->next;
        while(t2!=NULL){
            int a=t1->val;
            int b=t2->val;
            int x=__gcd(a,b);
            ListNode* node=new ListNode(x);
            t1->next=node;
            node->next=t2;
            t1=t1->next->next;
            t2=t2->next;
        }
        return head;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)return head;

        return solve(head);

    }
};