class Solution {
public:
    int solve(vector<vector<int>>& grid,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>>&dp){
        int n=grid.size(),m=grid[0].size();
        if(j1<0 || j1>=m || j2<0 || j2>=m || i1<0 || i2<0 || i1>=n || i2>=n){
            return 0;
        }
        
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];

        int x=0;
        x=max(x,solve(grid,i1+1,j1-1,i2+1,j2-1,dp));
        x=max(x,solve(grid,i1+1,j1-1,i2+1,j2,dp));
        x=max(x,solve(grid,i1+1,j1-1,i2+1,j2+1,dp));
        x=max(x,solve(grid,i1+1,j1,i2+1,j2-1,dp));
        x=max(x,solve(grid,i1+1,j1,i2+1,j2,dp));
        x=max(x,solve(grid,i1+1,j1,i2+1,j2+1,dp));
        x=max(x,solve(grid,i1+1,j1+1,i2+1,j2-1,dp));
        x=max(x,solve(grid,i1+1,j1+1,i2+1,j2,dp));
        x=max(x,solve(grid,i1+1,j1+1,i2+1,j2+1,dp));

        int y=(j1==j2)?grid[i1][j1]:grid[i1][j1]+grid[i2][j2];

        return dp[i1][j1][i2][j2]=x+y;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        std::vector<std::vector<std::vector<std::vector<int>>>> dp(n+1, 
        std::vector<std::vector<std::vector<int>>>(m+1, 
        std::vector<std::vector<int>>(n+1, 
        std::vector<int>(m+1, -1))));
        int x=solve(grid,0,0,0,m-1,dp);

        return x;
    }
};