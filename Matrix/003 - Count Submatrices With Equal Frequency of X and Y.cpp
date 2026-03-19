https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19

// same like yesterday problem only

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        vector<vector<int>>XTotal(m,vector<int>(n,0));
        vector<vector<int>>YTotal(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'X')
                {
                    XTotal[i][j] = 1; // if in grid[i][j] == 'x' then should include 
                }

                if(grid[i][j] == 'Y')
                {
                    YTotal[i][j] = 1; // if in grid[i][j] == 'x' then should include 
                }

                if(i>0) {
                    XTotal[i][j] += XTotal[i-1][j];
                    YTotal[i][j] += YTotal[i-1][j];
                }

                if(j>0){
                    XTotal[i][j] += XTotal[i][j-1];
                    YTotal[i][j] += YTotal[i][j-1];
                }

                if(i>0 && j>0){
                    XTotal[i][j] -= XTotal[i-1][j-1];
                    YTotal[i][j] -= YTotal[i-1][j-1];
                }

                if( XTotal[i][j] == YTotal[i][j] && XTotal[i][j] > 0)
                {
                    cnt++;
                }
            }

        }

        return cnt;
    }
};
