class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int &ans,  queue<pair<pair<int,int>,int>>&q){

        int n=grid.size();
        int m=grid[0].size();

        while(q.size()!=0){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int x=q.front().second;
            ans=max(ans,x);

            q.pop();

            if(row-1>=0&& grid[row-1][col]==1 && vis[row-1][col]==0){
                vis[row-1][col]=1;
                q.push({{row-1,col},x+1});
            }
            if(row>=0 && col-1>=0 && grid[row][col-1]==1 && vis[row][col-1]==0){
                vis[row][col-1]=1;
                q.push({{row,col-1},x+1});
            }
            if(row+1<n&& grid[row+1][col]==1 && vis[row+1][col]==0){
                vis[row+1][col]=1;
                q.push({{row+1,col},x+1});
            }
            if(col+1<m&& grid[row][col+1]==1 && vis[row][col+1]==0){
                vis[row][col+1]=1;
                q.push({{row,col+1},x+1});
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        bfs(grid,vis,ans,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return ans;
    }
};