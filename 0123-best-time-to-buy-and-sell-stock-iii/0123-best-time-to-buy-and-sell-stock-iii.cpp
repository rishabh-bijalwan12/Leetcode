class Solution {
public:
    int dp[100001][3][2];
    int solve(vector<int>&p,int k,int i,bool buy){
        if(i>=p.size())return 0;
        if(k==0)return 0;
        
        if(dp[i][k][buy]!=-1)return dp[i][k][buy];

        int ans=INT_MIN;

        if(buy==false){
            ans=max(solve(p,k,i+1,buy),-p[i]+solve(p,k,i+1,!buy));
        }
        else{
            ans=max(solve(p,k,i+1,buy),p[i]+solve(p,k-1,i+1,!buy));
        }
        return dp[i][k][buy]=ans;
    }
    int maxProfit(vector<int>& p) {
        int k=2;
        memset(dp,-1,sizeof(dp));
        return solve(p,k,0,false);
    }
};