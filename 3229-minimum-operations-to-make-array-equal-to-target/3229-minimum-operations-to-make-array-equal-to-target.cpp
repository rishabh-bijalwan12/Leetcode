class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& t) {
        long long ans=abs(t[0]-nums[0]),mini=t[0]-nums[0];
        for(int i=1;i<nums.size();i++){
            long long x=t[i]-nums[i];
            long long a=0;
            if(x < 0){
                if(mini<0){
                    if(mini<x){
                        mini=x;
                    }
                    else{
                        a=abs(abs(x)-abs(mini));
                        ans+=a;
                        mini=x;
                    }
                }
                else{
                    a=abs(x);
                    ans+=a;
                    mini=x;
                }
            }
            else{
                if(mini<0){
                    a=(x);
                    ans+=a;
                    mini=x;
                }
                else{
                    if(x>=mini){
                        a=x-mini;
                        ans+=a;
                    }
                    mini=x;
                }
            }
        }
        return ans;
    }
};