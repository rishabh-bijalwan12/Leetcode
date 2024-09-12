class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        unordered_map<char,int>mp;
        for(int i=0;i<a.size();i++)mp[a[i]]=1;
        int ans=0;
        for(int i=0;i<w.size();i++){
            string s=w[i];
            int f=0;
            for(int j=0;j<s.size();j++){
                if(mp.find(s[j])==mp.end()){
                    f=1;
                    break;
                }
            }
            if(f==0)ans++;
        }
        return ans;
    }
};