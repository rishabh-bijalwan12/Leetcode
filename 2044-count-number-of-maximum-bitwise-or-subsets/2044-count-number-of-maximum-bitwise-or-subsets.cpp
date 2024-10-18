class Solution {
public:
    int ans=0;
    int maxOr=-1;
    void solve(vector<int>&nums,vector<int>&t,int i){
        if(i>=nums.size()){
            int val=0;
            for(int k=0;k<t.size();k++){
                val=val|t[k];
            }
            maxOr=max(maxOr,val);
            return;
        }
        solve(nums,t,i+1);
        t.push_back(nums[i]);
        solve(nums,t,i+1);
        t.pop_back();
    }
    void solve2(vector<int>&nums,vector<int>&t,int i){
        if(i>=nums.size()){
            int val=0;
            for(int k=0;k<t.size();k++){
                val=val|t[k];
            }
            if(val==maxOr){
                ans+=1;
            }
            return;
        }
        solve2(nums,t,i+1);
        t.push_back(nums[i]);
        solve2(nums,t,i+1);
        t.pop_back();
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>t;
        solve(nums,t,0);
        t.clear();
        solve2(nums,t,0);
        return ans;
    }
};