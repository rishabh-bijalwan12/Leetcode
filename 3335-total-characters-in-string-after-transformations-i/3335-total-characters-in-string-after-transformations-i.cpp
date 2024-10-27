class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long>a(26,0);
        long long ans=s.size();
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        while(t--){
            vector<long long>b(26,0);
            for(int i=0;i<25;i++){
                b[i+1]=a[i];
            }
            ans=(ans%mod + a[25]%mod)%mod;
            b[0]=(b[0]%mod+a[25]%mod)%mod;
            b[1]=(b[1]%mod+a[25]%mod)%mod;
            a=b;
        }
        return ans;
    }
};