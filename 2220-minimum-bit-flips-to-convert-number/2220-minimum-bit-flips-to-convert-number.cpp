class Solution {
public:
    int minBitFlips(int s, int g) {
        int st=(s^g);
        int ans=0;
        cout<<st;
        for(int i=0;i<32;i++){
            if(st & (1<<i))ans++;
        }
        return ans;
    }
};