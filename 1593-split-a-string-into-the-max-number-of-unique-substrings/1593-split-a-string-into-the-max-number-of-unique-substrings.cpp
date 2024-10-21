class Solution {
public:
    set<string>st;
    int solve(string &s,int i,string t){
        if(i>=s.size())return 0;
        t+=s[i];
        int a=0,b=0;
        if(st.find(t)==st.end()){
            st.insert(t);
            a=1+solve(s,i+1,"");
            st.erase(t);
        }
        b=solve(s,i+1,t);
        return max(a,b);
    }
    int maxUniqueSplit(string s) {
        return solve(s,0,"");
    }
};