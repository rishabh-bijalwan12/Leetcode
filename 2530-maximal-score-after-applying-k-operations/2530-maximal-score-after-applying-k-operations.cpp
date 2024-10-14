class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq(nums.begin(),nums.end());
        long long ans=0;
        while(k>0){
            int t=pq.top();
            ans+=t;
            pq.pop();
            pq.push(((t+2)/3));
            k--;
        }    
        return ans;
    }
};