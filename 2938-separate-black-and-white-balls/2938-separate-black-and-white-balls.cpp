class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int i=s.size()-1,j=s.size()-1;
        while(i>=0){
            if(s[j]!='0'){
                i--,j--;
            }
            else{
                if(s[i]!='0'){
                    swap(s[i],s[j]);
                    ans+=(j-i);
                    i--,j--;
                }
                else{
                    i--;
                }
            }
        }
        return ans;
    }
};