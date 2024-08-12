class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp, mp2;
        for (int i = 0; i < s.size(); i++) mp[s[i]]++;
        
        int ans = s.size();
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) mp.erase(s[i]);
            
            if (mp.find(s[i]) != mp.end() && mp2.find(s[i]) != mp2.end()) {
                ans -= 2;
                mp2.erase(s[i]);
            } else {
                mp2[s[i]]++;
            }
        }
        return ans;
    }
};
