class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int>ans;
        for(int i=0;i<e.size();i++){
            char ch=e[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int>l,r;
                l=diffWaysToCompute(e.substr(0,i));
                r=diffWaysToCompute(e.substr(i+1));
  
                for(auto x:l){
                    for(auto y:r){
                        if(ch=='*')ans.push_back(x*y);
                        if(ch=='+')ans.push_back(x+y);
                        if(ch=='-')ans.push_back(x-y);
                    }
                }
            }
        }
        if(ans.size()==0)ans.push_back(stoi(e.substr(0)));
        return ans;
    }
};