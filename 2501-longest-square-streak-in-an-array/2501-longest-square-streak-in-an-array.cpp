class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<long long>st;
        for(auto x:nums)st.insert(x);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            long long x=nums[i];
            int val=1;
            while(st.find(x*x)!=st.end()){
                x=x*x;
                val++;
            }
            ans=max(ans,val);
        }
        return ans < 2  ? -1 : ans;
    }
};