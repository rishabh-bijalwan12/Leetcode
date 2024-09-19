class Solution {
public:
    long long dp[100001][2];
    long long f(vector<int>& nums,int i,int t){
        if(i>=nums.size())return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        long long  ans=-1e13;

        ans=max(ans,nums[i]+f(nums,i+1,1));

        if(t==0){
            ans=max(ans,nums[i]+f(nums,i+1,1));
        }
        else{
            ans=max(ans,-nums[i]+f(nums,i+1,0));
        }
        return dp[i][t]=ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0,0);
    }
};