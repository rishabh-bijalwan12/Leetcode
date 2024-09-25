class Solution {
public:
    struct trie{
        bool endOfWord;
        int val;
        trie *children[26];
    };
    trie *getNode(){
        trie* newNode=new trie();
        newNode->endOfWord=false;
        newNode->val=0;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(trie *root,string &s){
        int n=s.size();
        trie* temp=root;
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(temp->children[ch]==NULL){
                temp->children[ch]=getNode();
            }
            temp=temp->children[ch];
            temp->val+=1;
        }
        temp->endOfWord=true;
    }
    int search(trie* root,string &s){
        int n=s.size();
        int ans=0;
        trie* temp=root;
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            temp=temp->children[ch];
            ans+=temp->val;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trie *root=getNode();
        for(auto w:words){
            insert(root,w);
        }   
        vector<int>ans;
        for(auto w:words){
            int x=search(root,w);
            ans.push_back(x);
        }
        return ans;
    }
};