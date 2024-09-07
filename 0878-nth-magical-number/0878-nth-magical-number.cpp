class Solution {
public:
    #define mod 1000000007
    typedef long long ll;

    int nthMagicalNumber(int n, int a, int b) {
        ll l=1,h=1e14;
        ll ans=0;
        int LCM=lcm(a,b);
        while(l<=h){
            ll mid=l+(h-l)/2;
            ll x=mid/a;
            ll y=mid/b;
            ll z=mid/LCM;
            ll aa=(x+y-z);
            if(aa>=n){
                ans=mid;
                h=mid-1;
            }
            else if(aa<n)l=mid+1;
        }    
        return ans%mod;
    }
};