class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
        sort(in.begin(),in.end(),[](const auto & a,const auto &b){
            return a[1]<b[1];
        });
        
        int prev=in[0][0]-1,ans=0;

        for(int i=0;i<in.size();i++){
            int x=in[i][0];
            int y=in[i][1];
            if(x<prev){
                ans++;
            }
            else{
                prev=y;
            }
        }
        return ans;
    }
};