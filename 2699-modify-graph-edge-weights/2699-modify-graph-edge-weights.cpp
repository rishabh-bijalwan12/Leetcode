class Solution {
public:
    long long dijistra(int n,vector<vector<int>>& edges,int s,int d){
        vector<pair<long long,long long>>adj[n];
        for(auto &x:edges){
            if(x[2]!=-1){
                int u=x[0],v=x[1],w=x[2];
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        }
        priority_queue<pair<long long ,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,s});
        vector<long long>ans(n,2e9);
        ans[s]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            long long wt=pq.top().first;
            pq.pop();
            for(auto x:adj[node]){
                if(ans[x.first]>wt+x.second){
                    ans[x.first]=wt+x.second;
                    pq.push({wt+x.second,x.first});
                }
            }
        }

        return ans[d];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int s, int d, int t) {
        int ans=dijistra(n,edges,s,d);

        if(ans<t)return {};

        bool ch=(ans==t);

        for(auto &x:edges){
            if(x[2]==-1){
                x[2]=(ch==1)?2e9:1;
                if(ch==0){
                   int ans=dijistra(n,edges,s,d);
                    if(ans<=t){
                        x[2]+=(t-ans);
                        ch=1;
                    }
                }
            }
        }
        if(ch==0)return {};
        return edges;
    }
};