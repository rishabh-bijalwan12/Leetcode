class Solution {
public:
    int largestCombination(vector<int>& can) {
        int ans=-1e9;
        for(int i=0;i<24;i++){
            int x=0;
            for(int j=0;j<can.size();j++){
                if(can[j] & (1<<i))x++;
            }
            ans=max(ans,x);
        }
        return ans;
    }
};