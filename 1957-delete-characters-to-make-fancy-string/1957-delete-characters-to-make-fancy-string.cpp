class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int t=0;
        char ch=s[0];
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                t++;
                if(t<3){
                    ans+=s[i];
                }
            }
            else{
                ch=s[i];
                ans+=s[i];
                t=1;
            }
        }
        return ans;
    }
};