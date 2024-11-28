class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        int wt=(grid[0][0] == 0 )?0:1;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    int GridWt=(grid[newi][newj] == 0 )?0:1;
                    if(wt+GridWt < dis[newi][newj]){
                        dis[newi][newj]=wt+GridWt;
                        pq.push({wt+GridWt,{newi,newj}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};