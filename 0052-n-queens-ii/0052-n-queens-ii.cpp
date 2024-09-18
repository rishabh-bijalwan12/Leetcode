class Solution {
public:
    bool valid(vector<string>&b,int i,int j,int n){
        for(int k=0;k<n;k++)if(b[i][k]=='1')return false;
        for(int k=0;k<n;k++)if(b[k][j]=='1')return false;
        for(int x=i,y=j;x<n && y<n;x++,y++)if(b[x][y]=='1')return false;
        for(int x=i,y=j;x>=0 && y>=0;x--,y--)if(b[x][y]=='1')return false;
        for(int x=i,y=j;x>=0 && y<n;x--,y++)if(b[x][y]=='1')return false;
        for(int x=i,y=j;x<n && y>=0;x++,y--)if(b[x][y]=='1')return false;
        return true;
    }
    void solve(vector<string>&board ,int i,int n,int &ans){
        if(i>=n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(valid(board,i,j,n)){
                board[i][j]='1';
                solve(board,i+1,n,ans);
                board[i][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string>board(n,string(n,'.'));
        solve(board,0,n,ans);
        return ans;
    }
};