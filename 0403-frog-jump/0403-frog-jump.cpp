class Solution {
public:
    bool solve(vector<int>&s,int i,int j,vector<vector<int>>&dp,unordered_map<int,int>&mp){
        if(i==s.size()-1)return true;
        if(i>=s.size())return false;

        if(dp[i][j]!=-1)return dp[i][j];
        bool x=0,y=0,z=0;

        if(j-1>0 && mp.find(s[i]+(j-1))!=mp.end() )    
            x=solve(s,mp[s[i]+(j-1)],j-1,dp,mp);

        if(j>0 && mp.find(s[i]+(j))!=mp.end() )    
            y=solve(s,mp[s[i]+(j)],j,dp,mp);

        if(j+1>0 && mp.find(s[i]+(j+1))!=mp.end() )    
            z=solve(s,mp[s[i]+(j+1)],j+1,dp,mp);

      
        return dp[i][j]=x||y||z;
    }
    bool canCross(vector<int>& s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]=i;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,0,dp,mp);
    }
};