class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        vector<int>x(a.size(),0),ans;
        x[0]=a[0];
        for(int i=1;i<a.size();i++)x[i]+=x[i-1]^a[i];
        for(int i=0;i<q.size();i++){
            if(q[i][0]==0)ans.push_back(x[q[i][1]]);
            else ans.push_back(x[q[i][1]]^x[q[i][0]-1]);
        }
        return ans;
    }
};