class Solution {
public:
    struct trie{
        trie* children[26];
    };
    trie* getNode(){
        trie* newNode=new trie();
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(trie *root,string &s){
        int n=s.size();
        trie*temp=root;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=getNode();
            }
            temp=temp->children[idx];
        }
    }
    
    int dp[5001];
    int solve(trie* root,string &t,int i){
        if(i>=t.size())return 0;
        if(dp[i]!=-1)return dp[i];
        
        trie * temp=root;
        int ans=1e9;

        for(int j=i;j<t.size();j++){
            int idx=t[j]-'a';
            if(temp->children[idx]==NULL)break;
            temp=temp->children[idx];
            ans=min(ans,1+solve(root,t,j+1));
        }

        return dp[i]=ans;
    }
    int minValidStrings(vector<string>& w, string t) {
        int ans=0;
        trie* root=getNode();
        for(int i=0;i<w.size();i++){
            string s=w[i];
            insert(root,s);
        }
        int i=0;
        trie* temp=root;
        memset(dp,-1,sizeof(dp));
        ans=solve(root,t,0);
        return ans >= 1e9 ? -1 : ans ;
    }
};