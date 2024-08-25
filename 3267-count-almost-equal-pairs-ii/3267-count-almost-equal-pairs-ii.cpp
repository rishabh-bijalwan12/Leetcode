class Solution {
public:
    string make(int nums,int mx){
        string s=to_string(nums);
        while(s.size()!=mx)s="0"+s;
        return s;
    }
    unordered_set<string> solve(int nums,int mx){
        string s=make(nums,mx);
        unordered_set<string>st;
        st.insert(s);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                st.insert(s);
                for(int k=0;k<s.size();k++){
                    for(int l=k+1;l<s.size();l++){
                        swap(s[k],s[l]);
                        st.insert(s);
                        swap(s[k],s[l]);
                    }
                }
                swap(s[i],s[j]);
            }
        }
        return st;
    }
    int countPairs(vector<int>& nums) {
        int ans=0;
        int mx=to_string(*max_element(nums.begin(),nums.end())).size();// no of digit chahiya
        unordered_map<string,int>mp;
        for(int i=0;i<nums.size();i++){
            for(const auto &x:solve(nums[i],mx)){
                if(mp.find(x)!=mp.end())ans+=mp[x];
            }
            cout<<endl;
            string s=make(nums[i],mx);
            mp[s]++;
        }
        return ans;
    }
};