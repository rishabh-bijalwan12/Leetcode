class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]+=1;
        mp[end]+=-1;
        int val=0;
        for(auto x:mp){
            val+=x.second;
            if(val>=2){
                mp[start]-=1;
                mp[end]+=1;
                return false;
            }
        }
        return true;
    }
};
