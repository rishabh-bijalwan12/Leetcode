class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) dp[i][j]=solve(s,i+1,j-1,dp);
        else dp[i][j]=false;
        
        return dp[i][j];

    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string ans="";
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        ans=s.substr(i,maxi);
                    }
                }
            }
        }
        return ans;
    }
};