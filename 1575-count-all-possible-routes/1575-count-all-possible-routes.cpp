class Solution {
public:
    int dp[101][201];
    int mod=1000000007;
    int solve(vector<int>&l ,int i, int f,int fuel){
        if(fuel < 0){
            return 0;
        }
        if(dp[i][fuel]!=-1)return dp[i][fuel];
        int ans=0;     
        for(int j=0;j<l.size();j++){
            if(i==j)continue;
            int val=abs(l[i]-l[j]);
            if(j==f && fuel-val>=0)ans++;
            ans=((ans%mod)+(solve(l,j,f,fuel-val))%mod)%mod;
        }
        return dp[i][fuel]=ans;
    }
    int countRoutes(vector<int>& l, int s, int f, int fuel) {
        int x=(s==f)?1:0;
        memset(dp,-1,sizeof(dp));
        return solve(l,s,f,fuel)+x;
    }
};