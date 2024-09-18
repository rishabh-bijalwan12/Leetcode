class Solution {
public:
    int is(vector<int>&w,int m){
        int sum=0,d=1;
        for(int i=0;i<w.size();i++){
            if(sum+w[i] > m){
                sum=w[i];
                d++;
            }
            else{
                sum+=w[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int i=*max_element(w.begin(),w.end());
        int j=1e9,m=0,ans=0;
        while(i<=j){
            m=(i+j)/2;
            if(is(w,m) <= days){
                ans=m;
                j=m-1;
            }
            else i=m+1;
        }
        return ans;
    }
};