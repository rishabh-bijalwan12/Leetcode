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
    vector<int> NextGreater(ListNode* head){
        vector<int>a;
        ListNode* t=head;
        while(t!=NULL){
            a.push_back(t->val);
            t=t->next;
        }
        stack<int>st;
        for(int i=a.size()-1;i>=0;i--){
            while(st.size()!=0 && a[st.top()]<=a[i])st.pop();
            if(st.size()!=0)a[i]=-1;
            st.push(i);
        }
        return a;
    }

    ListNode* deleteNode(ListNode* head,vector<int>&a){
        ListNode* newNode=new ListNode(1);
        ListNode* temp=newNode;
        int i=0;
        while(head!=NULL){
            if(a[i]!=-1){
                temp->next=head;
                temp=temp->next;
            }
            head=head->next;
            i++;
        }
        return newNode->next;
    }
    ListNode* removeNodes(ListNode* head) {
        vector<int>a=NextGreater(head);
        ListNode* newNode=deleteNode(head,a);
        return newNode;
    }
};