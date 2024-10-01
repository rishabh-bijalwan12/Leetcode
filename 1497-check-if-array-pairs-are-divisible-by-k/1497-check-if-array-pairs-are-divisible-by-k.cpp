class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        sort(arr.rbegin(),arr.rend());
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int rem = ((arr[i] % k) + k) % k;
            mp[rem]++;        
        }
        for(auto &[a,b]:mp){
            if(a==0){
                if(b%2!=0)return false;
            }
            else{
                if(mp[k-a] != b)return false;
            }
        }
        return true;
    }
};