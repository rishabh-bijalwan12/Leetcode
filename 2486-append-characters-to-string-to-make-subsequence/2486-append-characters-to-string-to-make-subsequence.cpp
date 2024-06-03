class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int i=0,j=0;
        while(i!=s.size() && j!=t.size()){
            if(s[i]==t[j]){
                cout<<"S";
                i++,j++;
            }
            else{
                i++;
            }
        } 
        cout<<j;
        return t.size()-j;
    }
};