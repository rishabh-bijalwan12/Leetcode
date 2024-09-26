class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long currSum=0,size=nums.size(),i=0,ans=0;
        while(currSum<n){
            if(i<size && currSum+1 >= nums[i]){
                currSum+=nums[i];
                i++;
            }
            else{
                ans++;
                currSum+=(currSum+1);
            }
        }
        return ans;
    }
};