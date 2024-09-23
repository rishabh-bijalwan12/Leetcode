class Solution {
public:
    int dp[51];
    int solve(string s,unordered_set<string>st,int i){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        string ans="";
        int currVal=0;
        currVal=max(currVal,solve(s,st,i+1));
        for(int j=i;j<s.size();j++){
            ans+=s[j];
            if(st.find(ans)!=st.end()){
                currVal=max(currVal,solve(s,st,j+1)+(j-i+1));
            }
        }
        return dp[i]=currVal;
    }
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string>st;
        memset(dp,-1,sizeof(dp));
        for(auto x:d)st.insert(x);
        int ans=(s.size()-solve(s,st,0));
        return ans;
    }
};