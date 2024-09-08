class Solution {
public:
    typedef long long ll;
    bool check(vector<int>&a,int d,int m){
        ll x=a[0];
        for(int i=1;i<a.size();i++){
            if(x+m>a[i]+d)return false;
            x=max(1ll*a[i],x+m);
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        ll l=0,h=2e9,ans=0;
        sort(start.begin(),start.end());
        while(l<=h){
            ll mid=(l+h)/2;
            if(check(start,d,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};