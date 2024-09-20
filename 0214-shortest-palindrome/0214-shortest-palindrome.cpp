class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s.rbegin(), s.rend());

        for (int i = n; i >= 0; i--) {

            if (!memcmp(s.c_str(), rev.c_str() + (n - i), i)) {
                return rev.substr(0, n - i) + s;
            }
        }

        return s;
    }
};
