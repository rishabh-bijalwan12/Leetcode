class Solution {
public:
    int n,m;
    int dp[300][300];
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=solve(i,j+1,matrix);
        int right=solve(i+1,j,matrix);
        int diagnol=solve(i+1,j+1,matrix);

        return dp[i][j]=1+min(left,min(right,diagnol));
    }
    int countSquares(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(i,j,matrix);
            }
        }
        return ans;
    }
};