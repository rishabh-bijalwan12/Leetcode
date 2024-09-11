class Solution {
public:
    int dp[20001];
    
    int solve(vector<pair<int, int>>& nums, int i) {
        if(i==nums.size()-1)return nums[i].second;
        if (i >= nums.size()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int ans = 0;
        
        if(nums[i].first != nums[i+1].first+1){
            ans = max(ans, nums[i].second+solve(nums, i + 1));
        }
        else{
            ans=max(ans,max(nums[i].second+solve(nums,i+2),solve(nums,i+1)));
        }

        return dp[i]= ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        unordered_map<int, int> mp;
        
        for (auto x : nums) mp[x] += x;
        
        vector<pair<int, int>> x;
        for (auto a : mp) {
            x.push_back({a.first, a.second});
        }
        
        sort(x.rbegin(), x.rend());

        memset(dp, -1, sizeof(dp));
    
        return solve(x, 0);
    }
};
