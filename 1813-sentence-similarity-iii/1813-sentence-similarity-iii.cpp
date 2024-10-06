class Solution {
public:
    void get(string &s1,vector<string>&s11){
        int i=0;
        while(i<s1.size()){
            int j=i;
            string s="";
            while(j<s1.size() && s1[j]!=' ')s+=s1[j++];
            s11.push_back(s);
            i=j+1;
        }
    }
    bool areSentencesSimilar(string ss1, string ss2) {
        int n=ss1.size();
        int m=ss2.size();
        vector<string>s1,s2;
        get(ss1,s1);
        get(ss2,s2);
        if(s1.size()>s2.size()){
            swap(s1,s2);
        }
        int l=0,r=0;
        while(l<s1.size() && s1[l]==s2[l])l++;
        while(r<s1.size() && s1[s1.size()-r-1]==s2[s2.size()-r-1])r++;
        return l+r>=s1.size();
    }
};