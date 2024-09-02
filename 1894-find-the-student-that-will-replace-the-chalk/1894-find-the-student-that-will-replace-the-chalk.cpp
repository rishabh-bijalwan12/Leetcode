class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long x=0,n=chalk.size(),y=k;
        for(int i=0;i<n;i++){
            x+=chalk[i];
        }
        long long ans=k%x;
        for(int i=0;i<n;i++){
            ans-=chalk[i];
            if(ans<0)return i;
        }
        return 0;
    }
};


