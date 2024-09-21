class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& w) {
        int n=w.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            string ans=w[i];
            for(auto x:ans)mp[x]++;
        }
        int pairs=0,odd=0;
        vector<int>si;
        for(auto x:w)si.push_back(x.size());
        sort(si.begin(),si.end());
        for(auto &[a,b]:mp){
            pairs+=b/2;
            if(b%2!=0)odd++;
        }
        int ans=0;
        for(auto x:si){
            if(x%2==0){
                int req=x/2;
                if(pairs<req)ans--;
                pairs-=req;
            }
            else{
                int req1=x/2;
                int req2=1;
                
                if(pairs >=1 && odd==0){
                    odd+=2;
                    pairs--;
                }

                if(pairs<req1 || odd<req2)ans--;

                pairs-=req1;
                odd-=1;
            }
            ans++;
        }
        return ans;
    }
};