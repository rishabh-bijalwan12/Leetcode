class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int ind, int val) {
        multiset<int> st;
        int n = nums.size();

        for (int i = 0; i <= ind && i < n; ++i) {
            auto it = st.lower_bound(nums[i] - val);
            if (it != st.end() && *it <= nums[i] + val) {
                return true;
            }
            st.insert(nums[i]);
        }

        for (int i = 1, j = ind + 1; j < n; ++i, ++j) {
            st.erase(st.find(nums[i - 1]));
            auto it = st.lower_bound(nums[j] - val);
            if (it != st.end() && *it <= nums[j] + val) {
                return true;
            }
            st.insert(nums[j]);
        }

        return false;
    }
};
