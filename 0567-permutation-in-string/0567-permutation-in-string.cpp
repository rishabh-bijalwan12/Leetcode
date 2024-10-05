class Solution {
public:
    bool isEqual(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)return false;
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<n;i++){
            a[s1[i]-'a']++;
        }
        int i=0,j=0;
        while(j<n)b[s2[j++]-'a']++;
        for(int i=0;i<26;i++)cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<26;i++)cout<<b[i]<<" ";
        cout<<endl;
        cout<<endl;
        if(isEqual(a,b))return true;
        while(j<m){
            b[s2[j]-'a']++;
            b[s2[i]-'a']--;
            if(isEqual(a,b))return true;
            i++,j++;
        }
        return false;
    }
};