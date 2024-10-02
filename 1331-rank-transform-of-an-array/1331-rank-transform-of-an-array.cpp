class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int val=0,maxi=INT_MIN;
        map<pair<int,int>,int>mp;
        for(int i=0;i<arr.size();i++)mp[{arr[i],i}]++;
        for(auto &[a,b]:mp){
            int x=a.first;
            int y=a.second;
            if(maxi<x){
                maxi=x;
                val++;
            }
            arr[y]=val;
        }
        return arr;
    }
};