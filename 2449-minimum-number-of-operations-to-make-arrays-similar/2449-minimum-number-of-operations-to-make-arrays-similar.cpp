class Solution {
public:
    long long get(vector<int>&nums, vector<int>& target, int flag){
        int n = nums.size();
        vector<int> a,b;
        for(int i=0; i<n; i++){
            if(nums[i]%2==flag) a.push_back(nums[i]);
            if(target[i]%2==flag) b.push_back(target[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ans = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i]-b[i] > 0) ans += (a[i]-b[i])/2;
        }
        return ans;
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        return get(nums,target,0)+get(nums,target,1);
    }
};