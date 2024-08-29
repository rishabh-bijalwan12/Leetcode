class Solution {
public:
    int solve(vector<vector<int>>&s,int i,vector<int>&vis){
        
        vis[i]=1;

        int ans=0;

        int a1=s[i][0];
        int b1=s[i][1];

        for(int j=0;j<s.size();j++){
            int a2=s[j][0];
            int b2=s[j][1];

            if(vis[j])continue;

            if(a1==a2 || b1==b2){
                ans+=1+solve(s,j,vis);
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& s) {
        int ans=0;
        vector<int>vis(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(!vis[i])
                ans+=solve(s,i,vis);
        }
        return ans;
    }
};