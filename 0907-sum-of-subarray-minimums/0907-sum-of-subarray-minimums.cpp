class Solution {
public:
    int mod=1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0,n=arr.size();
        vector<int>lm(n,0),rm(n,0);
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            int x=1;
            while(!st.empty() && arr[st.top().first] > arr[i]){
                x+=st.top().second;
                st.pop();
            }
            lm[i]=x;
            st.push({i,x});
        }

        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            int x=1;
            while(!st.empty() && arr[st.top().first] >= arr[i]){
                x+=st.top().second;
                st.pop();
            }
            rm[i]=x;
            st.push({i,x});
        }

        for(int i=0;i<n;i++){
            long long x=((lm[i]%mod)*(rm[i])%mod)%mod;
            long long y=((arr[i]%mod)*(x)%mod)%mod;
            ans=((ans)%mod + (y)%mod)%mod;
        }
        
        return ans;
    }
};