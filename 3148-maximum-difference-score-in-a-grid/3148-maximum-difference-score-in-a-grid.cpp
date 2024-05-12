class Solution {
public:
    int f(vector<vector<int>>& a,int i,int j,vector<vector<int>>& dp){
        if(i>=a.size() || j>=a[0].size())return INT_MIN;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int x=INT_MIN,y=INT_MIN;
        
        if(i+1<a.size())x=(a[i+1][j]-a[i][j])+f(a,i+1,j,dp);
        if(j+1<a[0].size())y=(a[i][j+1]-a[i][j])+f(a,i,j+1,dp);
 
        return dp[i][j]=max(0,max(x,y));
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
    
  
        int maxi = INT_MIN,maxi2=INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ;++j) {
                maxi=max(maxi,f(grid,i,j,dp));
                if(i+1<n)maxi2=max(maxi2,grid[i+1][j]-grid[i][j]);
                if(j+1<m)maxi2=max(maxi2,grid[i][j+1]-grid[i][j]);
            }
        }
        if(maxi==0)return maxi2;
        return maxi;
    }
};