class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0;
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                x++;
                ans=max(ans,x);
            }
            else{
                x=0;
            }
        }
        return ans;
    }
};