class Solution {
public:
    vector<vector<string>>ans;
    bool valid(vector<string>&board,int i,int j,int n){
        //row and coloum
        for(int k=0;k<n;k++){
            if(board[i][k]=='Q')return false;
            if(board[k][j]=='Q')return false;
        }
        // \ diagnol
        int x=i,y=j;
        while(x<n && y<n){
            if(board[x][y]=='Q')return false;
            x++,y++;
        }
        x=i,y=j;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q')return false;
            x--,y--;
        }
        // / diagonal
        x=i,y=j;
        while(x>=0 && y>=0 && x<n && y<n){
            if(board[x][y]=='Q')return false;
            x++,y--;
        }
        x=i,y=j;
        while(x>=0 && y>=0 && x<n && y<n){
            if(board[x][y]=='Q')return false;
            x--,y++;
        }
        return true;
    }
    void solve(vector<string>&board ,int i,int q,int n){
        if(i>=n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(valid(board,i,j,n)){
                board[i][j]='Q';
                solve(board,i+1,q,n);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s=string(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        solve(board,0,0,n);
        return ans;
    }
};