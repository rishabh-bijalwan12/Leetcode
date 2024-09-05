class Solution {
public:
    int dp[201][201]; 
    int solve(vector<vector<int>>&mt,int i,int j,int prev,int n,int m){
        if (i < 0 || i >= n || j < 0 || j >= m || mt[i][j] <= prev) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        ans=max(ans,1+solve(mt,i+1,j,mt[i][j],n,m));
        ans=max(ans,1+solve(mt,i-1,j,mt[i][j],n,m));
        ans=max(ans,1+solve(mt,i,j+1,mt[i][j],n,m));
        ans=max(ans,1+solve(mt,i,j-1,mt[i][j],n,m));

        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mt) {
        int n=mt.size(),m=mt[0].size();
        int ans=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(mt,i,j,-1,n,m));
            }
        }
        return ans;
    }
};

