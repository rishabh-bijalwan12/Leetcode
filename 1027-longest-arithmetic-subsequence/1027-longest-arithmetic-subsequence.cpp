class Solution {

private:
    int dp[1001][1003];
    int solveMem(int index,int diff,vector<int> &nums)
    {
        if(index<0) return 0;

        if(dp[index][diff+501]!=-1) 
           return dp[index][diff+501];

        int ans=0;

        for(int j=index-1;j>=0;j--)
        {
            if(nums[index]-nums[j]==diff)
            {
                ans=max(ans,1+solveMem(j,diff,nums));
            }
        }

        return dp[index][diff+501]=ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
         int n=nums.size();
         if(n<=2) return n;

         int ans=0;

         memset(dp,-1,sizeof(dp));

         for(int i=0;i<n;i++)
         {
             for(int j=i+1;j<n;j++)
             {
                ans=max(ans,2+solveMem(i,nums[j]-nums[i],nums));
             }
         }
         return ans;

    }
};