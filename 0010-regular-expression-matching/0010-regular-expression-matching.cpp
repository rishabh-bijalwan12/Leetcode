class Solution {
public:
    bool solve(const string& s, const string& p, int i, int j, vector<vector<int>>& dp) {
        if (j < 0 && i < 0) return true; 
        if (j < 0) return false; 

        if (i < 0) {
            
            while (j > 0 && p[j] == '*') j -= 2;
            return j < 0;
        }

        if (dp[i][j] != -1) return dp[i][j]; 

        if (p[j] == '*') {
            
            bool x = solve(s, p, i, j - 2, dp);
            if (p[j-1] == s[i] || p[j-1] == '.') {
                x = x || solve(s, p, i - 1, j, dp); 
            }
            return dp[i][j] = x;
        }

        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp); 
            
        }

        return dp[i][j] = false; 
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, s.size() - 1, p.size() - 1, dp);
    }
};
