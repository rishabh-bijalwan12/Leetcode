class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        unordered_map<int,int>mp;
        priority_queue<int>q1;
        priority_queue<int ,vector<int>,greater<int>>q2;
        int i=0;


        for (i = 0; i < k; ++i) {
            if (q1.empty() || nums[i] <= q1.top()) {
                q1.push(nums[i]);
            } else {
                q2.push(nums[i]);
            }
            if (q1.size() < q2.size()) {
                q1.push(q2.top());
                q2.pop();
            } else if (q1.size() > q2.size() + 1) {
                q2.push(q1.top());
                q1.pop();
            }
        }
        
        if(k%2!=0)ans.push_back(q1.top());
        else ans.push_back((1ll*(q1.top())+q2.top())/2.0);
        
        for(int i=1,j=k;j<nums.size();i++,j++){
            mp[nums[i-1]]++;
            int come=nums[j];
            int b=0;

            if(q1.empty() || nums[i-1]<=q1.top()){
                b-=1;
            }
            else{
                b+=1;
            }

            if(!q1.empty() && come<=q1.top()){
                b+=1;
                q1.push(come);
            }
            else{
                b-=1;
                q2.push(come);
            }


            if(b<0){
                q1.push(q2.top());
                q2.pop();
            }
            else if(b>0){
                q2.push(q1.top());
                q1.pop();
            }

            while(!q1.empty() && mp.find(q1.top())!=mp.end()){
                mp[q1.top()]--;
                if(mp[q1.top()]==0)mp.erase(q1.top());
                q1.pop();
            }

            while(!q2.empty() && mp.find(q2.top())!=mp.end()){
                mp[q2.top()]--;
                if(mp[q2.top()]==0)mp.erase(q2.top());
                q2.pop();
            }


            if(k%2!=0)ans.push_back(q1.top());
            else ans.push_back((1ll*(q1.top())+q2.top())/2.0);
        }
        return ans;
    }
};