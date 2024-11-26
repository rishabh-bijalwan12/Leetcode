class Solution {
public:
    void dfs(vector<int>adj[],int node,int n,vector<int>&vis){
        vis[node]=1;
        for(auto Node:adj[node]){
            if(!vis[Node]){
                dfs(adj,Node,n,vis);
            }
        }
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>* adj = new vector<int>[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(adj,i,n,vis);
            int t=0;
            for(int j=0;j<n;j++){
                if(vis[j]==0)t=1;
            }
            if(t==0)return i;
        }
        return -1;
    }
};