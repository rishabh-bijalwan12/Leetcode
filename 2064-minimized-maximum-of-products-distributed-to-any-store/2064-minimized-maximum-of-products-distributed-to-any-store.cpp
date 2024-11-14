class Solution {
public:
    bool possible(vector<int>q,int val,int n){
        int grp=0;
        for(int i=0;i<q.size();i++){
            while(q[i]>0){
                q[i]-=val;
                grp++;
            }
            if(grp>n)return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int ans=0;
        int low=1,high=1e5;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(q,mid,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};