class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        
        // Sort by width in increasing order, and by height in decreasing order if the width is the same
        sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // We will only track heights and apply the LIS algorithm on them
        vector<int> temp;

        // Iterate through each envelope's height
        for (int i = 0; i < n; i++) {
            int height = e[i][1];
            
            // Use binary search to find the correct position in temp to replace or append
            auto it = lower_bound(temp.begin(), temp.end(), height);
            
            if (it == temp.end()) {
                // If height is larger than all elements in temp, append it
                temp.push_back(height);
            } else {
                // Otherwise, replace the found element with the current height
                *it = height;
            }
        }

        return temp.size();
    }
};
