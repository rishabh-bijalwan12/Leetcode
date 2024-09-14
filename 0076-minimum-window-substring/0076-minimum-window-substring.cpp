class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int>mp1,mp2;
        for(auto x:t)mp1[x]++;
        int uniq=mp1.size();
        int i=0,j=0,mini=INT_MAX,ele=0;
        int a=0,b=0;
        while(j<s.size()){
            char ch=s[j];
            mp2[ch]++;
            if(mp1.find(ch)!=mp1.end() && mp1[ch]==mp2[ch])ele++;
            if(ele==uniq){
                while(i <= j && ele==uniq){
                    if(mini>(j-i)+1){
                        mini=j-i+1;
                        a=i,b=mini;
                    }
                    char ch1=s[i];
                    mp2[ch1]--;
                    if(mp1.find(ch1)!=mp1.end() && mp1[ch1] > mp2[ch1])ele--;
                    i++;
                }
            }
            j++;
        }
        return s.substr(a,b);
    }
};