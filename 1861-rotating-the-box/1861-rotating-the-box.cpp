class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int row=0;row<n;row++){
            int i = m-1,j = m-1;
            while(i>=0){
                if(box[row][i] == '#'){
                    swap(box[row][i],box[row][j]);
                    i--,j--;
                }
                else if(box[row][i] == '*'){
                    i--;
                    j=i;
                }
                else{
                    i--;
                }
            }
        }
        int x = 0, y = 0;
        vector<vector<char>>ans;
        for(int i=0;i<m;i++){
            vector<char>temp;
            for(int j=0;j<n;j++){
                temp.push_back(box[j][i]);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<m;i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};