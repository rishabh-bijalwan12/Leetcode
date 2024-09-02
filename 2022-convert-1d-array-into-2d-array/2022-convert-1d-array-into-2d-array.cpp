class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        int x=0;
        vector<vector<int>>ans(m,vector<int>(n,0));
        if(o.size() != m*n)return{};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=o[x];
                x++;
            }
        }
        return ans;
    }
};