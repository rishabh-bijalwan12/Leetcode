class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int minTimeToReach(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>>pq;
        pq.push({0,0,0});
        dis[0][0]=0;
        while(!pq.empty()){
            auto [wt,i,j]=pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(newi>=0 && newi<n && newj>=0 && newj<m && dis[newi][newj] > max(wt+1,nums[newi][newj]+1)){
                    dis[newi][newj]=max(wt+1,nums[newi][newj]+1);
                    pq.push({dis[newi][newj],newi,newj});
                }
            }
        }
        return dis[n-1][m-1];
    }
};