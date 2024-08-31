class Solution {
public:
    vector<char> ch = {'a', 'b', 'c'};

    void solve(int n, int i, string &s, vector<string> &ans) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        
        for (int j = 0; j < 3; ++j) {
            if (s.empty() || s.back() != ch[j]) {
                s += ch[j];
                solve(n, i + 1, s, ans);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string s="";
        solve(n,0,s,ans);
        sort(ans.begin(),ans.end());
        if(k>ans.size())return "";
        return ans[k-1];
    }
};