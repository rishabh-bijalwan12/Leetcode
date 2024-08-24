class Solution {
public:
   void solve(string &n,long long left,bool even,string &ans,long long &mini,int len,bool x){
        long long t=left;
        if(!even)left/=10;
        while(left>0){
            t=(t*10)+left%10;
            left/=10;
        }
        
        if(abs(stoll(n)-t)<mini){
            mini=abs(stoll(n)-t);
            ans=to_string(t);
        }
        else if(abs(stoll(n)-t)==mini && x==true){
            mini=abs(stoll(n)-t);
            ans=to_string(t);
        }
    }

    string nearestPalindromic(string n) {
        string ans = "";
        bool even = (n.size() % 2 == 0);
        int len = n.size() / 2;
        if (even) len--;
        string s = n.substr(0, len + 1);
        long long left = stoll(s);
        long long mini = LLONG_MAX;

        if(n.size()==1 && n[0]=='1')return "0";

        // 1 case: make right part equal to left
        solve(n, left, even, ans, mini, len,false);
        if(mini==0)mini=LLONG_MAX;
        // cout<<mini;

        // 2 case: make right part equal to left but middle value decrease by 1
        solve(n, left - 1, even, ans, mini, len,true);

        // 3 case: make right part equal to left but middle value increase by 1
        solve(n, left + 1, even, ans, mini, len,false);

        // 4 case: make all 9s for n.size()-1 length
        long long t=0;
        for(int i=0;i<n.size()-1;i++){
            t=(t*10)+9;
        }
        long long fir=stoll(n);
        long long sec=t;
        long long diff=abs(fir-sec);

        if (diff <= mini) {
            mini = diff;
            ans = to_string(sec);
        }
        
        // 5 case: make all 100...001 for n.size()+1 length
        t=1;
        for(int i=1;i<n.size();i++){
            t=(t*10)+0;
        }
        t=(t*10)+1;

        fir=stoll(n);
        sec=t;
        diff=abs(fir-sec);

        if (diff <= mini) {
            mini = diff;
            ans = to_string(sec);
        }

        return ans;
    }
};
