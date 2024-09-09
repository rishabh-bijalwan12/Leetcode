class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int l=0,t=0,r=n-1,b=m-1,chance=0;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        while(head!=NULL){
            if(chance==0){
                for(int i=l;i<=r;i++){
                    if(head==NULL)break;
                    ans[t][i]=head->val;
                    head=head->next;
                }
                t++;
                chance=1;
            }

            if(chance==1){
                for(int i=t;i<=b;i++){
                    if(head==NULL)break;
                    ans[i][r]=head->val;
                    head=head->next;
                }
                r--;
                chance=2;
            }

            if(chance==2){
                for(int i=r;i>=l;i--){
                    if(head==NULL)break;
                    ans[b][i]=head->val;
                    head=head->next;
                }
                b--;
                chance=4;
            }
            
            if(chance==4){
                for(int i=b;i>=t;i--){
                    if(head==NULL)break;
                    ans[i][l]=head->val;
                    head=head->next;
                }
                l++;
                chance=0;
            }
        }
        return ans;
    }
};