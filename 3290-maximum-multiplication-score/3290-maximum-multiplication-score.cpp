class Solution {
public:
    vector<vector<long long>> memo;

    long long solve(int k, int index, vector<int>& a, vector<int>& b) {
        if (k == 4) return 0;
        
        if (index >= b.size()) return -1e18;
        
        if (memo[k][index] != -1) return memo[k][index];
        
        long long skip = solve(k, index + 1, a, b);
        
        long long take = a[k] * 1LL * b[index] + solve(k + 1, index + 1, a, b);
        
        return memo[k][index] = max(skip, take);
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        memo = vector<vector<long long>>(4, vector<long long>(n, -1));
        
        return solve(0, 0, a, b);
    }
};


