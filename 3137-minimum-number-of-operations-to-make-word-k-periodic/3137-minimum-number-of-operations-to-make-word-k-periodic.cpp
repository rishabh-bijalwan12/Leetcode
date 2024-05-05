class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        int b=0;
        while(b<word.size()){
            string str="";
            if(b+k>word.size())break;
            while(str.size()!=k){
                str+=word[b];
                b++;
            }
            mp[str]++;
        }
        int maxi=-1;
        int ans=0;
        for(auto x:mp){
            maxi=max(maxi,x.second);
            ans+=x.second;
        }
        return ans-maxi;
    }
};