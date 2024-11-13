class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int index1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int index2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            ans += max(0, index2 - index1 + 1);
        }
        return ans;
    }
};
