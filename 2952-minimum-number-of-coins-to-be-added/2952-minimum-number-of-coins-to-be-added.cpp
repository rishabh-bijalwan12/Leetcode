class Solution {
public:
    int minimumAddedCoins(vector<int>& nums, int n) {
        int currSum=0,size=nums.size(),i=0,ans=0;
        sort(nums.begin(),nums.end());
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