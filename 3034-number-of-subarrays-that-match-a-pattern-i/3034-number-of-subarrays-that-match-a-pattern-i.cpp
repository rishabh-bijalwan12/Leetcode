class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])nums[i]=1;
            else if(nums[i]==nums[i+1])nums[i]=0;
            if(nums[i]>nums[i+1])nums[i]=2;
        }
        for(auto &x:p)if(x==-1)x=2;
        string s1="",s2="";
        for(int i=0;i<n-1;i++)s1+=to_string(nums[i]);
        for(int i=0;i<p.size();i++)s2+=to_string(p[i]);
        n-=1;
        int i=0,j=s2.size()-1;
        string ans="";
        int x=0;
        for(int i=0;i<=j;i++)ans+=s1[i];
        if(ans==s2)x++;
        j++,i++;
        while(j<n){
            ans.erase(ans.begin());
            ans+=s1[j];
            if(ans==s2)x++;
            i++,j++;
        }
        return x;
    }
};