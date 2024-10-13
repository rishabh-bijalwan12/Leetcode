class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][5][2002];
    int solve(string &s, int i, char prev,int x) {
        if (i >= s.size()) {
            if(x>=1)return 1;
            return 0;
        }

        int prevIndex = (prev == 'F') ? 1 : (prev == 'W') ? 2 : (prev == 'E') ? 3 : 0;
        if (dp[i][prevIndex][x+1000] != -1) return dp[i][prevIndex][x+1000];

        char c = s[i];
        int y = 0;

        if (c == 'F') {
            if (prev != 'W') y = (y+solve(s, i + 1, 'W',x+1)) % mod; 
            if (prev != 'F') y = (y+solve(s, i + 1, 'F',x)) % mod; 
            if (prev != 'E') y = (y+solve(s, i + 1, 'E',x-1)) % mod; 
        } 
        else if (c == 'W') {
            if (prev != 'W') y = (y+solve(s, i + 1, 'W',x)) % mod; 
            if (prev != 'F') y = (y+solve(s, i + 1, 'F',x-1)) % mod; 
            if (prev != 'E') y = (y+solve(s, i + 1, 'E',x+1)) % mod; 
        } 
        else if (c == 'E') {
            if (prev != 'W') y = (y+solve(s, i + 1, 'W',x-1)) % mod; 
            if (prev != 'F') y = (y+solve(s, i + 1, 'F',x+1)) % mod; 
            if (prev != 'E') y = (y+solve(s, i + 1, 'E',x)) % mod; 
        }

        return dp[i][prevIndex][x+1000] = y;
    }

    int countWinningSequences(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 'x',0); 
    }
};
