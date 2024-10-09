class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,n=s.size();
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            else{
                close++;
                if(close>open){
                    ans++;
                    close--;
                }
                else{
                    open--,close--;
                }
            }
        }
        ans+=open;
        return ans;
    }
};