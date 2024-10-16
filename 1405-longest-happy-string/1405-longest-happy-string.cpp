class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a!=0)
            pq.push({a,'a'});
        if(b!=0)
            pq.push({b,'b'});
        if(c!=0)
            pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            auto x=pq.top();
            pq.pop();
            auto y=pq.top();
            pq.pop();
            int val=(x.first+1)/2;
            if(val > y.first){
                int val2=y.first;
                if(x.first >= 2){
                    ans+=x.second;
                    ans+=x.second;
                }
                else{
                    ans+=x.second;
                }
                ans+=y.second;
                if(x.first-2 > 0)
                    pq.push({x.first-2,x.second});
                if(y.first-1 > 0)
                    pq.push({y.first-1,y.second});
            }
            else{
                int val2=val;
                int extra=1;
                if(x.first >= 2){
                    ans+=x.second;
                    ans+=x.second;
                }
                else{
                    ans+=x.second;
                }
                if(y.first >= 2){
                    ans+=y.second;
                    ans+=y.second;
                }
                else{
                    ans+=y.second;
                }
                if(x.first-2 > 0)
                    pq.push({x.first-2,x.second});
                if(y.first-2 > 0 && extra != 0)
                    pq.push({y.first-2,y.second});
            }
        }
        if(pq.size()==1){
            auto x=pq.top();
            pq.pop();
            if(ans.size()==0){
                if(x.first==1){
                    ans+=x.second;
                    return ans;
                }
                else{
                    ans+=x.second;
                    ans+=x.second;
                    return ans;
                }
            }
            if(x.second != ans.back()){
                if(x.first == 1){
                    ans+=x.second;
                }
                else{
                    ans+=x.second;
                    ans+=x.second;
                }
            }
            else{
                if(ans[ans.size()-2]!=x.second){
                    ans+=x.second;
                }
            }
        }
        return ans;
    }
};