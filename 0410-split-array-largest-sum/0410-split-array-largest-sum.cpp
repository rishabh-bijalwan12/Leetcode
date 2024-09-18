class Solution {
public:
    bool is(vector<int>& nums, int k, int t) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > t) {
                k--;
                sum = 0;
            }
            sum += nums[i];
            if (k < 0) return false;
        }
        return k > 0;
    }

    int splitArray(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        int j = 1e9;
        int ans = j;

        while (i <= j) {
            int mid = (i + j) / 2;
            if (is(nums, k, mid)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return ans;
    }
};
