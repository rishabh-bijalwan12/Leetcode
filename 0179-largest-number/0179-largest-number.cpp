class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp=[](auto &a,auto &b){
            if(to_string(a)+to_string(b)>to_string(b)+to_string(a)){
                return true;
            }
            else{
                return false;
            }
        };
        string ans="";
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0)return "0";
        for(auto x:nums)ans+=to_string(x);
        return ans;
    }
};