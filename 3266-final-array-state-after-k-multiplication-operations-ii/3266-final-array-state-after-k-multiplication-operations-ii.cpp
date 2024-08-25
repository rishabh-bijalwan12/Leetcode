class Solution {
public:
    int mod = 1e9+7;

    // Function to perform modular exponentiation
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If exp is odd, multiply base with result
                result = (result * base) % mod;
            }
            base = (base * base) % mod;  // Square the base
            exp /= 2;  // Reduce exponent by half
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        if(m==1)return nums;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        for (int i = 0; i < nums.size(); i++) q.push({nums[i], i});
        
        int mx=*max_element(nums.begin(),nums.end());

        while (q.top().first*m <= mx && k > 0) {
            long long x = q.top().first;
            int i = q.top().second;
            q.pop();
            x = (x * m) % mod;
            q.push({x, i});
            k--;
        }

        long long mul = power(m,k/nums.size(),mod) % mod;
        int rem=k%nums.size();


        while (!q.empty()) {
            long long x = q.top().first;
            int i = q.top().second;
            if(k%nums.size()!=0){
                nums[i]=(x%mod*m%mod)%mod*mul%mod;
                k--;
            }
            else
                nums[i] = ((x)%mod * mul)%mod;
            q.pop();
        }

        return nums;
    }
};
