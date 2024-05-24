class Solution {
public:
    int f(vector<string>& words,unordered_map<char,int>&mp,vector<int>&score,int i){
        if(i>=words.size())return 0;
        
        int a=f(words,mp,score,i+1);//not take

        string s=words[i];
        int b=0,zz=0,sum=0,f1=0;  //take
        for(int j=0;j<s.size();j++){
            if(mp.find(s[j])!=mp.end()){
                int ch=s[j]-'a';
                sum+=score[ch];
                mp[s[j]]--;
                if(mp[s[j]]==0)mp.erase(s[j]);
                zz++;
            }
            else{
                sum=0,f1=1;
                break;
            }
        }
        if(f1!=1){
            b=sum+f(words,mp,score,i+1);
        }
        for(int j=0;j<zz;j++){
            mp[s[j]]++;
        }

        return max(a,b);
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto x:letters)mp[x]++;
        return f(words,mp,score,0);
    }
};