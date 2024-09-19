typedef long long ll;
class Solution {
public:
    ll inf=-1e18;
    ll solve(vector<int>& nums,int k,int i,int t,vector<vector<vector<ll>>>&dp){
        if(k==0)return 0;
        if(i>=nums.size())return inf;
        if(dp[i][k][t]!=inf)return dp[i][k][t];
        ll ans=inf;
        int aa=(t==1)?-1:1;
        ans=max(ans,aa*k*(ll)nums[i]+solve(nums,k,i+1,t,dp));

        if(t==0){
            ans=max(ans,(k*(ll)nums[i])+solve(nums,k-1,i+1,1,dp));
        }
        else{
            ans=max(ans,(-(k*(ll)nums[i])+solve(nums,k-1,i+1,0,dp)));
        }
        return dp[i][k][t]=ans;
    }
    ll maximumStrength(vector<int>& nums, int k) {
        ll ans=inf;
        int n=nums.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(2, inf)));
        for(int i=0;i<nums.size();i++){
            ans=max(ans,solve(nums,k,i,0,dp));
        }
        return ans;  
    }
};