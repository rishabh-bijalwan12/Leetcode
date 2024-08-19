class Solution {
public:
    // Function to fill a string with character x, n times
    void fill(int n, char x, string &s) {
        for(int i = 0; i < n; i++) s += x;
    }

    // Function to check if a number (given as string) is divisible by 7
    bool div(string num) {
        int n = num.length(), gSum = 0;

        if (n == 0) return true;
        
        // Append required 0s at the beginning
        if (n % 3 == 1) {
            num = "00" + num;
            n += 2;
        } else if (n % 3 == 2) {
            num = "0" + num;
            n++;
        }

        // Add digits in group of three in gSum
        int i, GSum = 0, p = 1;
        for (i = n - 1; i >= 0; i--) {
            int group = 0;
            group += num[i--] - '0';
            group += (num[i--] - '0') * 10;
            group += (num[i] - '0') * 100;

            gSum += group * p;
            p *= -1;
        }

        return (gSum % 7 == 0);
    }

    string largestPalindrome(int n, int k) {
        string s = "";

        fill(n, '9', s);

        if (k == 1 || k == 3 || k == 9) {
            return s;
        }

        if (k == 2) {
            if (n == 1) return "8";
            if (n == 2) return "88";
            s[0] = s[n-1] = '8';
            return s;
        }

        if (k == 4) {
            if (n == 1) return "8";
            if (n == 2) return "88";
            if (n == 3) return "888";
            s[0] = s[1] = s[n-1] = s[n-2] = '8';
            return s;
        }

        if (k == 5) {
            if (n == 1) return "5";
            if (n == 2) return "55";
            s[0] = s[n-1] = '5';
            return s;
        }

        if (k == 6) {
            if (n == 1) return "6";
            if (n == 2) return "66";
            s[0] = s[n-1] = '8';
            int x = n * 9 - 2;
            if (x % 3 != 0) {
                if (n % 2 == 0) {
                    s[(n/2)-1] = s[(n/2)] = '7';
                } else {
                    s[n/2] = '8';
                }
            }
            return s;
        }

        if (k == 7) {
            for (char i = '9'; i >= '0'; i--) {
                s[n/2] = s[(n-1)/2] = i;
                if (div(s)) return s;
            }
        }

        if (k == 8) {
            if (n == 1) return "8";
            if (n == 2) return "88";
            s[0] = s[1] = s[2] = s[n-1] = s[n-2] = s[n-3] = '8';
            return s;
        }

        return "";
    }
};
