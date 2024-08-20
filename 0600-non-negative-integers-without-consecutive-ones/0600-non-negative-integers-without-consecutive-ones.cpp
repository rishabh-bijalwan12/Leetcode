class Solution {
    
    int memo[32][2][2];
    string num;

    int dp(int pos, int small, int prev) {
        if (pos == num.size()) return 1;
        if (memo[pos][small][prev] != -1) return memo[pos][small][prev];
        int ans = 0;
        // Can place 0 or 1
        if (small) { 
            if (prev == 1) // no consecutive ones
                ans += dp(pos + 1, true, 0);
            else
                ans += dp(pos + 1, true, 1) + dp(pos + 1, true, 0);
        }
        else {
            // Can place 0 or 1
            if (num[pos] == '1') {
                if (prev == 1) // no consecutive ones 
                    ans += dp(pos + 1, true, 0);
                else
                    ans += dp(pos + 1, true, 0) + dp(pos + 1, false, 1);
            }
            else {
                // only can place 0 and small still false
                ans += dp(pos + 1, false, 0);
            }
        }
        return memo[pos][small][prev] = ans;
    }

    string toBinary(int x) {
        string s;
        while (x) {
            if (x & 1)
                s.push_back('1');
            else
                s.push_back('0');
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    int findIntegers(int n) {
        num = toBinary(n);
        memset(memo, -1, sizeof(memo));
        return dp(0, false, 0);
    }
};