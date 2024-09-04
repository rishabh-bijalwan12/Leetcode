class Solution {
public:
    int dp[31][31][31][31];

    bool solve(int a, int b, int c, int d, string &s1, string &s2) {
    
        if (s1.substr(a, b - a) == s2.substr(c, d - c)) return true;

        if (dp[a][b][c][d] != -1) return dp[a][b][c][d];

        int n = b - a;

        for (int j = 1; j < n; j++) {
            // Case 1: No swap between the two substrings
            if (solve(a, a + j, c, c + j, s1, s2) && solve(a + j, b, c + j, d, s1, s2)) 
                return dp[a][b][c][d] = true;

            // Case 2: Swap between the two substrings
            if (solve(a, a + j, d - j, d, s1, s2) && solve(a + j, b, c, d - j, s1, s2)) 
                return dp[a][b][c][d] = true;
        }

        return dp[a][b][c][d] = false;
    }

    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s1.size(), 0, s2.size(), s1, s2);
    }
};
