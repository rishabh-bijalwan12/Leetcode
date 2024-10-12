class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0,n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(!pq.empty() && pq.top()<intervals[i][0]){
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else{
                pq.push(intervals[i][1]);
                ans++;
            }
        }
        return ans;
    }
};