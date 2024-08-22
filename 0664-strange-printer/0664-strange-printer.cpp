class Solution {
public: 
    // int dp[101][101];
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i==j)return 1;

        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            ans=min(ans,solve(s,i,k,dp)+solve(s,k+1,j,dp));
        }

        if(s[i]==s[j])ans-=1;

        return dp[i][j]=ans;
        
    }
    int strangePrinter(string s) {
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,s.size()-1,dp);
    }
};