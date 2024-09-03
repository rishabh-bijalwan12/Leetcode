class Solution {
public:
    void doo(string &s){
        int x=0;
        for(int i=0;i<s.size();i++){
            x+=(s[i]-'0');
        }
        s=to_string(x);
    }
    int getLucky(string s, int k) {
        string st;
        for(int i=0;i<s.size();i++){
            int x=(s[i]-'a')+1;
            st+=to_string(x);
        }
        while(k!=0){
            doo(st);
            k--;
        }
        return stoi(st);
    }
};