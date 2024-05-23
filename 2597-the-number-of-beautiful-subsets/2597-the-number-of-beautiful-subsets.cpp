class Solution {
public:
    void f(vector<int>&nums,int k,int i,int &ans,vector<int>&a){
        if(i>=nums.size()){
            if(a.size()>=1)
            ans=ans+1;
            return;
        }
        f(nums,k,i+1,ans,a);
        int f1=0;
        for(int j=0;j<a.size();j++){
            if(abs(a[j]-nums[i])==k){
                f1=1;
                break;
            }
        }
        if(f1!=1){
            a.push_back(nums[i]);
            f(nums,k,i+1,ans,a);
            a.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>a;
        int ans=0;
        f(nums,k,0,ans,a);
        return ans;
    }
};