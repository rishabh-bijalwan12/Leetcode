class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>ans;
        int mini=INT_MAX;
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                ans.push_back({nums[i][j],i});
            }
        }
        if(ans.size()==1)return {ans[0].first,ans[0].first};
        sort(ans.begin(),ans.end());
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<ans.size()){
            mp[ans[r].second]++;
            while(l<r && mp.size()==nums.size()){
                if(ans[r].first-ans[l].first < mini){
                    mini=ans[r].first-ans[l].first;
                    x=ans[l].first,y=ans[r].first;
                }
                mp[ans[l].second]--;
                if(mp[ans[l].second]==0)mp.erase(ans[l].second);
                l++;
            }
            r++;
        }
        return {x,y};
    }
};