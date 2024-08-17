class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ml=v[0],ans=INT_MIN;
        for(int i=1;i<v.size();i++){  
            int x=ml+v[i]-i;
            ans=max(ans,x);
            if(ml<=v[i]+i)ml=v[i]+i;
        }
        return ans;
    }
};