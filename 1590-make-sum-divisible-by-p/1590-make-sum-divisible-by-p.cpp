class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n=nums.size(),mini=INT_MAX,ans=0,currSum=0;
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        unordered_map<long long,long long>mp;
        int val=sum%p;
        if(val==0)return 0;
        if(p>sum)return -1;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            long long rem=(currSum)%p;
            long long need=(rem-val+p)%p;
            if(mp.find(need)!=mp.end()){
                mini=min(mini,i-mp[need]);
            }
            mp[rem]=i;
        }
        return mini>=n?-1:mini;
    }
};