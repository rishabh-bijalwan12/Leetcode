class Solution {
public:
    int minLength(string s) {
        int t=0;
        while(t!=1 && s.size()!=0){
            int x=0;
            for(int i=0;i<s.size()-1;i++){
                if((s[i]=='A'&&s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                    s.erase(i,2);
                    x=1;
                    break;
                }
            }
            cout<<endl;
            if(x==0)t=1;
        }
        return s.size();
    }
};