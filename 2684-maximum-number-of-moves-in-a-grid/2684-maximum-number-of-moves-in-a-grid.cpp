class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(vector<vector<int>>& grid,int i,int j,int prev){
        if(i<0 || j<0 || i>=n || j>=m || prev>=grid[i][j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=1+solve(grid,i-1,j+1,grid[i][j]);
        int mid=1+solve(grid,i,j+1,grid[i][j]);
        int down=1+solve(grid,i+1,j+1,grid[i][j]);

        return dp[i][j]=max({up,mid,down});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(grid,i,0,0));
        }
        return ans-1;
    }
};