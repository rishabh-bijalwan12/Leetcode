class Solution {
public:
    char solve(vector<int>& o, long long k, int i) {
        if (i < 0) return 'a';
        long long x = (i >= 63) ? LLONG_MAX : 1LL << i;

        if (k <= x) {
            return solve(o, k, i - 1);
        }
        else {
            k -= x;
            char c = solve(o, k, i - 1);
            if (o[i] == 1) {
                if (c == 'z') return 'a';
                return char(c + 1);
            }
            else {
                return c;
            }
        }
    }

    char kthCharacter(long long k, vector<int>& o) {
        return solve(o, k, o.size() - 1);
    }
};
