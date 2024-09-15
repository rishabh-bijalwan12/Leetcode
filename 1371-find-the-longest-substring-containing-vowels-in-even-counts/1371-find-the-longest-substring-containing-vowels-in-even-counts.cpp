class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int>mp;
        vector<int>x(5,0);
        int maxi=0;
        mp["00000"]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')x[0]=(x[0]+1)%2;
            if(s[i]=='e')x[1]=(x[1]+1)%2;
            if(s[i]=='i')x[2]=(x[2]+1)%2;
            if(s[i]=='o')x[3]=(x[3]+1)%2;
            if(s[i]=='u')x[4]=(x[4]+1)%2;

            string st="";
            for(int k=0;k<5;k++)st+=to_string(x[k]);
            if(mp.find(st)!=mp.end())maxi=max(maxi,i-mp[st]);
            else mp[st]=i;
        }
        return maxi;
    }
};