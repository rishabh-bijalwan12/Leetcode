class Solution {
public:
    int dp[2001][2001];

    bool palin( int left, int right,string &s) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int f(int i ,int j,string &s) {
        int n=s.size();
        if (i>=n) return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if (palin(i,j,s)) return 0; 

        int ans = s.size() - 1;

        for (int k = i; k < n; k++) {
            if (palin(i,k,s)) {
                ans = min(ans, 1 + f(k+1,j,s));
            }
        }

        return dp[i][j] = ans;
    }

    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s.size()-1,s);
    }
};
