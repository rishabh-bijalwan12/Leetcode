class AllOne {
public:
    unordered_map<string,int>mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0)mp.erase(key);
    }
    
    string getMaxKey() {
        int maxi=-1;
        string ans="";
        for(auto &[a,b]:mp){
            if(b>maxi){
                maxi=b;
                ans=a;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        int mini=1e9;
        string ans="";
        for(auto &[a,b]:mp){
            if(b<mini){
                mini=b;
                ans=a;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */