class Solution {
public:
    int solve(vector<string>&nums,int n,int m,int i,vector<vector<vector<int>>>&dp){
        if(i<0 || (n<=0 && m<=0))return 0;
        int x=0;
        if(dp[i][n][m]!=-1)return dp[i][n][m];
        
        int a=count(nums[i].begin(),nums[i].end(),'0');
        int b=count(nums[i].begin(),nums[i].end(),'1');

        if(a<=n && b<=m){
            x=1+solve(nums,n-a,m-b,i-1,dp);
        }
        int y=0+solve(nums,n,m,i-1,dp);

        return dp[i][n][m]=max(x,y);
    }
    int findMaxForm(vector<string>& nums, int m, int n) {
        int n1=nums.size();
        vector<vector<vector<int>>>dp(n1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(nums,m,n,n1-1,dp);
    }
};