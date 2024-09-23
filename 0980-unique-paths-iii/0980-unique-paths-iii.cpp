class Solution {
public:
    int vis[21][21];
    int solve(vector<vector<int>>& g, int val, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || val < 0 || g[i][j] == -1) 
            return 0;
        
        if(g[i][j] == 2) return val == 0 ? 1 : 0;
        
        int ans = 0;
        vis[i][j] = 1;
        
        ans += solve(g, val-1, i + 1, j, n, m);
        ans += solve(g, val-1, i - 1, j, n, m);
        ans += solve(g, val-1, i, j + 1, n, m);
        ans += solve(g, val-1, i, j - 1, n, m);
        
        vis[i][j] = 0;
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int obs = 0, nonObs = n * m, x1 = 0, y1 = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == -1) obs++;
                if(grid[i][j] == 1) {
                    x1 = i;
                    y1 = j;
                }
            }
        }
        
        nonObs -= obs;
        nonObs -= 1;
        memset(vis, 0, sizeof(vis));
        
        return solve(grid, nonObs, x1, y1, n, m);
    }
};
