class Solution {
public:
    int length(ListNode* head){
        int ans=0;
        ListNode *t=head;
        while(t!=NULL){
            ans++;
            t=t->next;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        vector<ListNode*>ans;
        len=length(head);
        if(k==1){
            return {head};
        }
        if(len<k){
            while(k!=0){
                if(head!=NULL){
                    ListNode *t=head;
                    head=head->next;
                    t->next=NULL;
                    ans.push_back(t);
                }
                else{
                    ans.push_back(NULL);
                }
                k--;
            }
        }
        else{
            int x=len%k;
            k=len/k;
            k=k+1;

            ListNode* t1=head;

            int a=0,FT=0;

            while(t1!=NULL){
                if(x==0 && FT==0)k-=1,FT=1;
                ListNode* t2=t1;
                int temp=0;
                a=0;
                while(a<k-1){
                    if(t1==NULL){
                        temp=1;
                        break;
                    }
                    t1=t1->next;
                    a++;
                }
                if(temp==0){
                    head=t1->next;
                    t1->next=NULL;
                    t1=head;
                }
                ans.push_back(t2);
                x--;
            }
        }
        return ans;
    }
};