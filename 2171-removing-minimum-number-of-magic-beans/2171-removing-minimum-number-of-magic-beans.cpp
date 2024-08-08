class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>a(n,0);
        a[0]=nums[0];
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+nums[i];
        }
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            long long x=a[n-1]-a[i];
            long long y=a[i]-nums[i];
            long long z=y+(x-nums[i]*(long long)(n-i-1));
            ans=min(ans,z);
        }
        return ans;
    }
};