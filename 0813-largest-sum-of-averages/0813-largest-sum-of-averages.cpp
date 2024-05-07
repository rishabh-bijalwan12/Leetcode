class Solution {
public:
    double solve(vector<int>&nums,int k,int ind,vector<vector<double>>&dp){
        if(ind>=nums.size())return 0;
        double ans=0;
        int count=0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        if(k==1){
            for(int i=ind;i<nums.size();i++){
                ans+=nums[i];
                count++;
            }
            return dp[ind][k]=ans/count;
        }
        double sum=0;
        for(int i=ind;i<nums.size();i++){
            sum+=nums[i];
            count++;
            ans=max(ans,sum/count+solve(nums,k-1,i+1,dp));
        }
        return dp[ind][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>>dp(105,vector<double>(105,-1));
        double x=0;
        return solve(nums,k,0,dp);
    }
};