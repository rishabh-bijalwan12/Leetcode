class Solution {
public:
    typedef long long ll;
    ll count(ll curr,ll next,ll n){
        ll element=0;
        while(curr<=n){
            element+=next-curr; 
            curr*=10;
            next*=10;
            next=min(next,n+1);
        }
        return element;
    }
    int findKthNumber(ll n, ll k) {
        ll curr=1;
        if(k==1)return curr;
        k--;
        while(k>0){
            ll x=count(curr,curr+1,n);
            if(x<=k){
                k-=x;
                curr=curr+1;
            }
            else{
                k--;
                curr=curr*10;
            }
        }
        return curr;
    }
};