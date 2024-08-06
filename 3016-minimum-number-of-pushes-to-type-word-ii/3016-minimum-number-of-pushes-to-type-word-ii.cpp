class Solution {
public:
    int minimumPushes(string s){
        int n=s.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[s[i]]++;
        vector<int>a;
        for(auto x:mp){
            a.push_back(x.second);
        }
        sort(a.begin(),a.end());
        long long ans=0,sec=0;
        for(int i=a.size()-1;i>=0;){
            int x=0;
            while(i>=0 && x!=8){
                if(sec==0){
                    ans+=a[i];
                }
                else if(sec==1){
                    ans+=(2*a[i]);
                }
                else if(sec==2){
                    ans+=(3*a[i]);
                }
                else{
                    ans+=(4*a[i]);
                }
                x++,i--;
            }
            sec+=1;
        }
        return ans;
    }
};