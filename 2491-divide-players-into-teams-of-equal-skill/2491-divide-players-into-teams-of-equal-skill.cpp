class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        long long ans=0;
        int x=s[0]+s[n-1];
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]+s[j]!=x)return -1;
            ans+=(s[i]*s[j]);
            i++,j--;
        }
        return ans;
    }
};