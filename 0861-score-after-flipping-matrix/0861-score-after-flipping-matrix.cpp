class Solution {
public:
    int m = 0;
    int n = 0;

    void flipRow(vector<vector<int>> &grid, int r)
    {
        for(int c=0; c<n; c++)
        {
            if(grid[r][c] == 0)
                grid[r][c] = 1;
            else
                grid[r][c] = 0;
        }
    }

    void flipCol(vector<vector<int>> &grid, int c)
    {
        for(int r=0; r<m; r++)
        {
            if(grid[r][c] == 0)
                grid[r][c] = 1;
            else
                grid[r][c] = 0;
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        m = size(grid);
        n = size(grid[0]);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][0] == 0)
                {
                    flipRow(grid, i);
                }
            }
        }
        

        for(int j=0; j<n; j++)
        {
            int cntZero = 0;
            for(int i=0; i<m; i++)
            {
                if(grid[i][j] == 0)
                {
                    cntZero++;
                }
            }

            if(m-cntZero < cntZero)
            {
                flipCol(grid, j);
            }
        }

        int temp = 1,ans=0;

        for(int i=0; i<m; i++)
        {
            temp = 0;
            for(int j=0; j<n; j++)
            {
                int p = pow(2,n-j-1);
                temp+=(p*grid[i][j]);
            }
            ans+=temp;
        }

       return ans;
    }
};