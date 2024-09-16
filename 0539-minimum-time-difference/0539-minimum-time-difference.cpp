class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int n = t.size();
        vector<int> times;

        for (string& time : t) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            times.push_back(hours * 60 + minutes);
        }

        sort(times.begin(), times.end());

        int mini = INT_MAX;

        for (int i = 1; i < n; i++) {
            mini = min(mini, times[i] - times[i - 1]);
        }

        mini = min(mini, 1440 - (times[n - 1] - times[0]));

        return mini;
    }
};
