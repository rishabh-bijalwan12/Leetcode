class Solution {
public:
    vector<int>ans;
    void solve(int n,string s){
        if(s.size() != 0 && stoi(s)>n)return;
        for(char i='0';i<='9';i++){
            if(s.size()==0 && i=='0')continue;
            s+=i;
            if(stoi(s)<=n)
                ans.push_back(stoi(s));
            solve(n,s);
            s.pop_back();
        }
    }
    vector<int> lexicalOrder(int n) {
        solve(n,"");
        return ans;
    }
};