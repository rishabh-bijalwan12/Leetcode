class Solution {
public:
    int dp[101][101][2];
    int solve(vector<int>&p,int i,int m,bool ch){
        if(i>=p.size())return 0;
        if(dp[i][m][ch]!=-1)return dp[i][m][ch];
        
        int x=(ch)?-1:INT_MAX,n=p.size();
        int a=0,b=min(2*m,n-i);
        for(int j=1;j<=b;j++){
            if(ch){
                a+=p[i+j-1];
                x=max(x,a+solve(p,i+j,max(m,j),!ch));
            }
            else{
                x=min(x,solve(p,i+j,max(m,j),!ch));
            }
        }

        return dp[i][m][ch]=x;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,1,true);
    }
};