class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        long long ans=0;
        long long sum=0;
        while(j<nums.size()){
            if(j-i+1<k){
                mp[nums[j]]++;
                sum+=nums[j];
                j++;
            }
            else{
                mp[nums[j]]++;
                sum+=nums[j];
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
               mp[nums[i]]--;
               if(mp[nums[i]]==0)mp.erase(nums[i]);
                sum-=nums[i];
                i++,j++;
            }
        }
        return ans;
    }
};