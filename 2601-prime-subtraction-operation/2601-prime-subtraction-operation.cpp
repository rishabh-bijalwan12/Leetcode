class Solution {
public:
    bool is(int x){
        for(int i=2;i<=x/2;i++){
            if(x%i==0)return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>p;
        int max=*max_element(nums.begin(),nums.end());
        for(int i=2;i<=max;i++){
            if(is(i))p.push_back(i);
        }
        int prev=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int mini=nums[i];
            for(int j=0;j<p.size();j++){
                if(p[j]<x && x-p[j]>prev){
                    
                    mini=min(mini,x-p[j]);
                }
            }
            prev=mini;
            nums[i]=mini;
        }
        for(int i=1;i<nums.size();i++)if(nums[i-1]>=nums[i])return false;
        return true;
    }
};