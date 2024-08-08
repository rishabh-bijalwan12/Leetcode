class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0,ans2=INT_MIN,n=nums.size();
        if(n==1)return 0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]*i);
        }
        for(int i=n-1;i>0;i--){
            ans2=max(ans2,ans);
            ans=ans+sum-(n)*nums[i];
            ans2=max(ans2,ans);

        }
        return ans2;
    }
};