class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size(),ans=INT_MAX;
        vector<int>one(k+1,0);
        
        unordered_map<int,int>mp;

        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int x=abs(a-b);
            mp[x]++;
            int mini=min(a,b);
            int maxi=max(a,b);
            int y=max(maxi,(k-mini));
            one[y]++;
        }

        for(int i=k-1;i>=0;i--)one[i]=one[i]+one[i+1];

        for(auto &[x,y]:mp){
            int onei=one[x]-y;
            int two=n/2-y-onei;
            ans=min(ans,(onei+2*two));
        }
        return ans;
    }
};