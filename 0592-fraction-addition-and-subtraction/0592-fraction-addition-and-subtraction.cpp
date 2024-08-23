class Solution {
public:
    string fractionAddition(string e) {
        long long x = 0, y = 1;
        int j = 0;
        if(e[0]!='-')e.insert(e.begin(),'+');

        while (j < e.size()) {
            int sign = (e[j] == '-') ? -1 : 1;
            j++;
            int num = e[j] - '0';
            if(num==1 && e[j+1]=='0'){
                num=num*10+(e[j+1]-'0');
                j++;
            }
            j += 2;
            int denom = e[j] - '0';
            if(denom==1 && e[j+1]=='0'){
                denom=denom*10+(e[j+1]-'0');
                j++;
            }
            j++;

            x = x * denom + num * y * sign;
            y = abs(y * denom);

            // Reduce the fraction
            long long gcd = __gcd(abs(x), y);
            x /= gcd;
            y /= gcd;
            y=abs(y);

        }

        return to_string(x) + "/" + to_string(y);
    }
};
