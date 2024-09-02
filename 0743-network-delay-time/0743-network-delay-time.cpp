class Solution {
public:
    typedef long long ll;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int ,ll>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>ans(n+1,INT_MAX);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0,k});
        ans[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            ll wt=pq.top().first;
            pq.pop();
            for(auto x:adj[node]){
                if(ans[x.first] > x.second+wt){
                    ans[x.first]=x.second+wt;
                    pq.push({x.second+wt,x.first});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<ans.size();i++){
            cout<<ans[i]<<" ";
            if(ans[i]==INT_MAX)return -1;
            maxi=max(maxi,ans[i]);
        }    
        return maxi;
    }
};