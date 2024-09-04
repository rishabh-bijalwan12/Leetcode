class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        set<pair<int,int>> st;
        for (int i = 0; i < o.size(); i++) st.insert({o[i][0], o[i][1]});

        int x1 = 0, y1 = 0, t = 2;
        int maxi = INT_MIN;

        for (int i = 0; i < c.size(); i++) {
            maxi = max(maxi, (x1 * x1) + (y1 * y1));
            
            if (c[i] == -1) {
                if (t == 0) t = 2;
                else if (t == 1) t = 3;
                else if (t == 2) t = 1;
                else if (t == 3) t = 0;
            }
            else if (c[i] == -2) {
                if (t == 0) t = 3;
                else if (t == 1) t = 2;
                else if (t == 2) t = 0;
                else if (t == 3) t = 1;
            }
            else {
                if (t == 0) {
                    int temp = x1;
                    for (int j = 0; j < c[i]; j++) {
                        temp -= 1;
                        if (!st.empty() && st.find({temp, y1}) != st.end()) {
                            temp += 1;
                            break;
                        }
                    }
                    x1 = temp;
                }
                else if (t == 1) {
                    int temp = x1;
                    for (int j = 0; j < c[i]; j++) {
                        temp += 1;
                        if (!st.empty() && st.find({temp, y1}) != st.end()) {
                            temp -= 1;
                            break;
                        }
                    }
                    x1 = temp;
                }
                else if (t == 2) {
                    int temp = y1;
                    for (int j = 0; j < c[i]; j++) {
                        temp += 1;
                        if (!st.empty() && st.find({x1, temp}) != st.end()) {
                            temp -= 1;
                            break;
                        }
                    }
                    y1 = temp;
                }
                else if (t == 3) {
                    int temp = y1;
                    for (int j = 0; j < c[i]; j++) {
                        temp -= 1;
                        if (!st.empty() && st.find({x1, temp}) != st.end()) {
                            temp += 1;
                            break;
                        }
                    }
                    y1 = temp;
                }
            }
            cout << x1 << " " << y1 << " " << t << endl;
        }
        maxi = max(maxi, (x1 * x1) + (y1 * y1));
        return maxi;
    }
};
