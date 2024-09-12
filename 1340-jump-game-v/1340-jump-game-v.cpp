class Solution {
public:
    int dp[1001];
    int solve(vector<int>&arr,int d,int i){
        if(i<0 || i>=arr.size())return 0;
        
        if(dp[i]!=-1)return dp[i];

        int ans=1;
        int maxi=arr[i];

        for(int j=i+1;j<arr.size()&&abs(j-i)<=d;j++){
            if(arr[j] >= maxi)break;
            ans=max(ans,1+solve(arr,d,j));
        }
        for(int j=i-1;j>=0&&abs(i-j)<=d;j--){
            if(arr[j] >= maxi)break;
            ans=max(ans,1+solve(arr,d,j));
        }
        return dp[i]=ans;

    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=0,n=arr.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(arr,d,i));
        }
        return ans;
    }
};