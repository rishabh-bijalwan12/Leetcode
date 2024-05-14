class Solution {
public:
    vector<vector<int>>vis;
    int f(vector<vector<int>>& a,int i,int j){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==0 || vis[i][j]==1)return 0;
        int x=0,b=0,c=0,d=0;
        vis[i][j]=1;
        x=f(a,i+1,j);
        b=f(a,i-1,j);
        c=f(a,i,j+1);
        d=f(a,i,j-1);
        vis[i][j]=0;
        return a[i][j]+max(max(x,b),max(c,d));

    }
    int getMaximumGold(vector<vector<int>>& a) {
        int m=INT_MIN;
        vis.resize(a.size(), vector<int>(a[0].size(), 0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                m=max(m,f(a,i,j));
            }
        }
        return m;
    }
};