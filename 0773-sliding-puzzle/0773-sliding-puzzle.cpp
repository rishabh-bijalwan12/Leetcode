class Solution {
public:
    string convert(vector<vector<int>>& b){
        string ans="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                ans+=to_string(b[i][j]);
            }
       }
       return ans;
    }
    int get(string &s){
        for(int i=0;i<6;i++){
            if(s[i]=='0')return i;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>poss = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string s = convert(board);
        string target = "123450";
        int lev = 0;
        queue<string>q;
        q.push(s);

        set<string>vis;
        vis.insert(s);

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string t = q.front();
                q.pop();
                if(t == target)return lev;
                int getZero = get(t);
                for(int i=0;i<poss[getZero].size();i++){
                    string newS = t;
                    swap(newS[poss[getZero][i]],newS[getZero]);
                    if(vis.find(newS) == vis.end()){
                        vis.insert(newS);
                        q.push(newS);
                    }
                }
            }
            lev++;
        }
        return -1;
    }
};