class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        if(s1.size()>s2.size())return false;
        for(auto x:s1)mp1[x]++;
        for(int i=0;i<s1.size();i++)mp2[s2[i]]++;
        if(mp1==mp2)return true;
        for(int i=1,j=s1.size();j<s2.size();i++,j++){
            mp2[s2[i-1]]--;
            if(mp2[s2[i-1]]==0)mp2.erase(s2[i-1]);
            mp2[s2[j]]++;
            if(mp1==mp2)return true;
        }
        return false;
    }
};