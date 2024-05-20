class Solution {
public:
    int f(vector<int>&nums,int i,int ans){
        if(i>=nums.size()){
            return ans;
        }
        int x=f(nums,i+1,ans^nums[i]);
        int y=0^f(nums,i+1,ans);

        return x+y;
    }
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
};