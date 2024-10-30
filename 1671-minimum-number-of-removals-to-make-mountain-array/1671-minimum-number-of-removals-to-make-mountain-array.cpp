class Solution {
public:
    int LIS(vector<int>& nums, vector<int>& lis, int idx) {
        if (lis[idx] != -1) return lis[idx];
        lis[idx] = 1;
        for (int i = 0; i < idx; i++) {
            if (nums[idx] > nums[i]) {
                lis[idx] = max(lis[idx], LIS(nums, lis, i) + 1);
            }
        }
        return lis[idx];
    }

    int LDS(vector<int>& nums, vector<int>& lds, int idx) {
        if (lds[idx] != -1) return lds[idx];
        lds[idx] = 1;
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[idx] > nums[i]) {
                lds[idx] = max(lds[idx], LDS(nums, lds, i) + 1);
            }
        }
        return lds[idx];
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> lis(n, -1), lds(n, -1);

        for (int i = 0; i < n; i++) {
            LIS(nums, lis, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            LDS(nums, lds, i);
        }

        int maxMountainLen = 0;

        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountainLen = max(maxMountainLen, lis[i] + lds[i] - 1);
            }
        }

        return n - maxMountainLen;
    }
};