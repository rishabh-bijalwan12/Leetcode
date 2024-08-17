class Solution {
public:
    // long long solve(vector<vector<int>>&p ,int row,int col,vector<vector<long long>>&dp){
    //     if(row>=p.size() || col>=p[0].size())return 0;

    //     if(dp[row][col]!=-1)return dp[row][col];

    //     long long ans=INT_MIN;
    //     vector<long long>l(p[0].size(),0);
    //     vector<long long>r(p[0].size(),0);
        


    //     // for(int i=0;i<p[0].size();i++){
    //     //     ans=max(ans,p[row][col]-abs(col-i)+solve(p,row+1,i,dp));
    //     // }

    //     ans=max(ans,p[i][j]+solve())

    //     return dp[row][col]=ans;
    // }
    long long maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int m=p[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        // long long ans=INT_MIN;
        // for(int i=0;i<m;i++){
        //     ans=max(ans,solve(p,0,i,dp));
        // }

        for(int i=0;i<m;i++){
            dp[0][i]=p[0][i];
        }

        for(int i=1;i<n;i++){
            vector<long long>l(m,0);
            vector<long long>r(m,0);

            l[0]=dp[i-1][0];
            r[m-1]=dp[i-1][m-1];

            for(int j=1;j<m;j++){
                l[j]=max(dp[i-1][j],l[j-1]-1);
            }
            for(int j=m-2;j>=0;j--){
                r[j]=max(dp[i-1][j],r[j+1]-1);
            }

            for(int j=0;j<m;j++){
                dp[i][j]=max(l[j],r[j])+p[i][j];
            }
        }
        long long ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,dp[n-1][i]);
        }

        return ans;
    }
};