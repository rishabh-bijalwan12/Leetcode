class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int n=times.size(),ans=0,at=0,i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int target=times[t][0];
        vector<int>st(n,0);
        sort(times.begin(),times.end());
        for(int i=0;i<n;i++){
            at=times[i][0];
            while(!pq.empty() && pq.top().first<=at){
                int ind=pq.top().second;
                pq.pop();
                st[ind]=0;
            }
            int val=0;
            while(st[val]==1)val++;
            if(times[i][0] == target)return val;
            pq.push({times[i][1],val});
            st[val]=1;
        }
        return ans;
    }
};