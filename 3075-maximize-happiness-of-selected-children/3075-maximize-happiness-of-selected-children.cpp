class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        long long ans=0;
        int x=0;
        int i=0;
        while(k>0){
            h[i]=(h[i]-x<0)?0:h[i]-x;
            ans+=h[i];
            i++;
            x++;
            k--;
        }
        return ans;
    }
};