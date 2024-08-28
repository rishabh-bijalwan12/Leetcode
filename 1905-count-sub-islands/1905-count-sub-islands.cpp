class Solution {
public:
    bool dfs(vector<vector<int>>& g1,vector<vector<int>>& g2,vector<vector<int>>& vis,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || g2[i][j]==0)return 1;

        if(g1[i][j]==0 && g2[i][j]==1)return 0;
        
        vis[i][j]=1;

        bool a=0,b=0,c=0,d=0;

        a=dfs(g1,g2,vis,i,j+1,n,m);
        b=dfs(g1,g2,vis,i+1,j,n,m);
        c=dfs(g1,g2,vis,i,j-1,n,m);
        d=dfs(g1,g2,vis,i-1,j,n,m);
            
        return a&b&c&d;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n=g1.size();
        int m=g1[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g1[i][j]==0 || g2[i][j]==0 || vis[i][j]==1)continue;
                if(dfs(g1,g2,vis,i,j,n,m))ans++;
            }
        }
        return ans;
    }
};