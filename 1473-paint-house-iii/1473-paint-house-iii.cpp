class Solution {
public:
    int dp[101][101][22];
    int solve(vector<int>& h, vector<vector<int>>& c, int n, int m, int t,int i,int p){
        if(i>=n && t==0)return 0;
        if(i>=n || t<0)return 1e9;
        
        if(dp[i][t][p+1]!=-1)return dp[i][t][p+1];

        int ans=INT_MAX;

        if(h[i]!=0){
            if(p==h[i]-1){
                ans=min(ans,solve(h,c,n,m,t,i+1,p));
            }
            else{
                ans=min(ans,solve(h,c,n,m,t-1,i+1,h[i]-1));
            }   
        }
        else{
            for(int j=0;j<m;j++){
                if(p==j){
                    ans=min(ans,c[i][j]+solve(h,c,n,m,t,i+1,j));
                }
                else{
                    ans=min(ans,c[i][j]+solve(h,c,n,m,t-1,i+1,j));
                }
            }

        }
        return dp[i][t][p+1]=ans;

    }
    int minCost(vector<int>& h, vector<vector<int>>& c, int n, int m, int t) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(h,c,n,m,t,0,-1);
        return (ans>=1e9)?-1:ans;
    }
};