class Solution {
public:
    int minSwaps(string s) {
        int ans=0,n=s.size();
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='[')open++;
            if(s[i]==']'){
                close++;
                if(open < close){
                    open++;
                    close--;
                }
                else{
                    open--;
                    close--;
                }
            }
        }
        return (open+close)/2;
    }
};