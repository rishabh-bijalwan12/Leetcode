class Solution {
public:
    int bs(vector<vector<int>>& nums, int val) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m][0] <= val) {
                ans = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& nums, vector<int>& q) {
        int n = nums.size(), m = q.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++) {
            nums[i][1] = max(nums[i][1], nums[i - 1][1]);
        }
        
        for (int i = 0; i < m; i++) {
            int val = q[i];
            int index = bs(nums, val);
            int x = (index == -1) ? 0 : nums[index][1];
            ans.push_back(x);
        }
        
        return ans;
    }
};
