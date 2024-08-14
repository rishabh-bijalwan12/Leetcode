class Solution {
public:
    int minNumberOperations(vector<int>& t) {
        int ans=t[0],mini=t[0];
        for(int i=1;i<t.size();i++){
            if(t[i]>=mini){
                ans+=(t[i]-mini);
                mini=t[i];
            }
            else{
                mini=t[i];
            }
        }
        return ans;
    }
};