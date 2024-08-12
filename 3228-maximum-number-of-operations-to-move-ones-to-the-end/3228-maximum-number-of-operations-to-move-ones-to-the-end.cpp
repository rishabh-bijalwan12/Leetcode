class Solution {
public:
    int maxOperations(string s) {
        int x=0;
        int ans=0,i=s.size()-1;
        if(s.size()==1)return 0;
        while(i>=0 && s[i]=='1')i--;
        while(i>=0){
            if(s[i+1]=='0' && s[i]=='1')x+=1;
            if(s[i]=='1')ans+=x;
            i--;
        }
        return ans;
    }
};