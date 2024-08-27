class Solution {
public:
    double ans = 1e-5;

    void dfs(int node, vector<pair<int, double>> adj[], vector<int>& vis, int e, double sum) {
        if(sum<=ans)return;
        if (node == e) {
            ans = max(ans, sum);
            return;
        }

        vis[node] = 1;
        for (auto& Node : adj[node]) {
            int nextNode = Node.first;
            double prob = Node.second;
            if (!vis[nextNode] && sum * prob >= ans) {
                dfs(nextNode, adj, vis, e, sum * prob);
            }
        }
        vis[node] = 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& ss, int s, int e) {
        vector<pair<int, double>> adj[n];
        vector<int> vis(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, ss[i]});
            adj[v].push_back({u, ss[i]});
        }

        dfs(s, adj, vis, e, 1.0);  
        return ans;
    }
};
