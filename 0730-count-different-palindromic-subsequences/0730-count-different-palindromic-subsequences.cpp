class Solution {
public:
    int mod=1000000007;
    int dp[1001][1001];
    
    int solve(string &s ,int i ,int j) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) {
            int x = (2 * solve(s, i + 1, j - 1)) % mod;
            int l = i + 1, r = j - 1;
            
            while(l <= r && s[l] != s[i]) l++;
            while(l <= r && s[r] != s[i]) r--;
            
            if(l < r) {
                x = (x - solve(s, l + 1, r - 1)%mod + mod) % mod;
            } else if(l == r) {
                x = (x + 1) % mod;
            } else {
                x = (x + 2) % mod;
            }
            
            return dp[i][j] = x;
        } else {
            return dp[i][j] = ((solve(s, i + 1, j) + solve(s, i, j - 1)) % mod - solve(s, i + 1, j - 1) + mod) % mod;
        }
    }
    
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n - 1);
    }
};
