class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& f, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 0; i < f.size(); i++) {
            int u = f[i][0], v = f[i][1], w = f[i][2];
            adj[u].emplace_back(v, w);
        }
        
        // Priority Queue to store (stops, cost, node)
        priority_queue<tuple<int, int, int>, vector<std::tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, src});  // {stops, cost, node}
        
        vector<int> ans(n, INT_MAX);  // Minimum cost to reach each node
        ans[src] = 0;
        
        while (!pq.empty()) {
            auto [stops, currCost, node] = pq.top();  // Unpack tuple into variables
            pq.pop();
            
            // If the number of stops exceeds the limit, skip this path
            if (stops > k) continue;
            
            // Explore neighbors of the current node
            for (auto& [nextNode, nextWeight] : adj[node]) {
                int newCost = currCost + nextWeight;
                
                // If the new cost is cheaper, or we can reach the node with fewer stops, push it to the queue
                if (newCost < ans[nextNode]) {
                    ans[nextNode] = newCost;
                    pq.push({stops + 1, newCost, nextNode});
                }
            }
        }

        // Return the minimum cost to reach the destination or -1 if it's not reachable
        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};
