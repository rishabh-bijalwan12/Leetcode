class Solution {
public:
    
    struct trie{
        bool end;
        trie * children[26];
        string word;
    };

    trie * getNode(){
        trie *newNode=new trie;
        newNode->end=false;
        newNode->word="";
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    void insert(trie* root,string &s){
        int n=s.size();
        trie *t=root;
        for(int i=0;i<n;i++){
            char ch=s[i]-'a';
            if(t->children[ch]==NULL){
                t->children[ch]=getNode();
            }
            t=t->children[ch];
        }
        t->end=true;
        t->word=s;
    }

    vector<string>ans;

    void solve(vector<vector<char>>&b,int i,int j,int n,int m,trie* root){
        if(i<0 || j<0 || j>=m || i>=n || b[i][j]=='1' || root->children[b[i][j]-'a']==NULL )return ;
       
        char ch=b[i][j];
        b[i][j]='1';
        root=root->children[ch-'a'];

        if(root->end==true){
            ans.push_back(root->word);
            root->end=false;
        }

        solve(b,i+1,j,n,m,root);
        solve(b,i-1,j,n,m,root);
        solve(b,i,j+1,n,m,root);
        solve(b,i,j-1,n,m,root);

        b[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        int n=b.size(),m=b[0].size();
        trie * root=getNode();
        for(auto &x:w)insert(root,x);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(b,i,j,n,m,root);
            }
        }
        return ans;
    }
};