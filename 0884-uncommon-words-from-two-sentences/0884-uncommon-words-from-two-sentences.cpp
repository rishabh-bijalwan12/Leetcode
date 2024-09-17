class Solution {
public:
    unordered_map<string,int>mp;
    void doo(string &s){
        int i=0;
        string str="";
        while(i<s.size()){
            while(i<s.size() && s[i]!=' '){
                str+=s[i];
                i++;
            }
            mp[str]++;
            str="";
            i++;
        }
        mp[str]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        doo(s1);
        doo(s2);
        for(auto &[a,b]:mp){
            if(b==1){
                ans.push_back(a);
            }
        }
        return ans;
    }
};