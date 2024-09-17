class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        vector<int>ans(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push({'(',i});
            else{
                if(!st.empty() && st.top().first=='('){
                    ans[st.top().second]=1;
                    ans[i]=1;
                    st.pop();
                }
            }
        }
        int maxi=0,t=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                t++;
                maxi=max(maxi,t);
            }
            else{
                t=0;
            }
        }
        return maxi;
    }
};