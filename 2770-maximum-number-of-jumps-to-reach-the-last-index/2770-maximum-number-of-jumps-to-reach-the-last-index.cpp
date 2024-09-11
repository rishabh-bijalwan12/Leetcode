class Solution {
public:
    int dp[1001];
    int solve(vector<int>& nums, int t,int i,int n){
        if(i==n-1)return 0;
        if(i>=n)return INT_MIN;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        for(int j=i+1;j<n;j++){
            if(nums[j]-nums[i] >= -1*t && nums[j]-nums[i]<=t){
                ans=max(ans,1+solve(nums,t,j,n));
            }
        }
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int t) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,t,0,n);
        return (ans<0)?-1:ans;
    }
};