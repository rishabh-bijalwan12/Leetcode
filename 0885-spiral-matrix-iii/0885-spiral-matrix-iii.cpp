class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>nums(rows,vector<int>(cols,0));
        int n=nums.size(),m=nums[0].size();
        vector<vector<int>>ans;
        int le=0,tp=0;
        int i=rStart;
        int j=cStart;
        int d=0;
        // ans.push_back({i,j});
        while(ans.size()<(rows*cols)){
            int k=0;
            if(d==0){
                le++;
                while( k!=le){
                    if(i>=0 && j>=0 && i<n && j<m)
                        ans.push_back({i,j});
                    j++,k++;
                }
                d=1;
            }
            else if(d==1){
                k=0;
                tp++;
                while(k!=tp){
                    if(i>=0 && j>=0 && i<n && j<m)
                        ans.push_back({i,j});
                    i++,k++;
                }
                d=2;
            }
            else if(d==2){
                k=0;
                le++;
                while(k!=le){
                    if(i>=0 && j>=0 && i<n && j<m)
                        ans.push_back({i,j});
                    j--,k++;
                }
                d=3;
            }
            else if(d==3){            
                k=0;
                tp++;
                while(k!=tp){
                    if(i>=0 && j>=0 && i<n && j<m)
                        ans.push_back({i,j});
                    i--,k++;
                }
                d=0;
            }
        }

        return ans;
    }
};