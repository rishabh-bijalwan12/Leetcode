class Solution {
public:
    long long dp[100005][3][2];
    int solve(int n, int id, int countL, bool isAbs){
        if(id == n + 1){
            return 1;
        }
        if(dp[id][countL][isAbs] != -1)
            return dp[id][countL][isAbs];
        long count = 0;
        if(!isAbs){
            count += solve(n, id + 1, 0, true) % 1000000007; 
        }
        if(countL < 2){
            count += solve(n, id + 1, countL + 1, isAbs) % 1000000007;
        }
        count += solve(n, id + 1, 0, isAbs) % 1000000007;

        return dp[id][countL][isAbs] = count % 1000000007;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 1, 0, false);
    }
};