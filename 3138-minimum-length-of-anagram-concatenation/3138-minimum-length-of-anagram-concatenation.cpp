class Solution {
public:
    bool f(string s,int x){
        vector<int>a(26,0);
        for(int i=0;i<x;i++){
            a[s[i]-'a']++;
        }
        
        int val=0;
        for(int i=x;i<s.size();){
            val+=x;
            vector<int>b(26,0);
            while(val!=0){
                b[s[i]-'a']++;
                val--;
                i++;
            }
            if(a!=b)return false;
        }
        return true;
    }
    int minAnagramLength(string s) {
        for(int i=0;i<s.size();i++){
            if(s.size()%(i+1)==0 && f(s,i+1))return i+1;
        }
        return s.size();
    }
};