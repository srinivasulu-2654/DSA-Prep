/* 
https://leetcode.com/problems/number-of-enclaves/description/
-> Same to same as like "Surrounded Regions" this problem
-> the only thing we have to traverse is just explore 1's in boundaries
-> and make them to check with vis array and grid array
-> grid[i][j] != vis[i][j]
*/

class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                vis[nrow][ncol] = 1;
                dfs(nrow,ncol,grid,vis);
            }
        }

        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        // cols

        for(int i=0;i<m;i++)
        {
            // first col
            if(!vis[i][0] && grid[i][0] == 1)
            {
                dfs(i,0,grid,vis);
            }
            //last col
            if(!vis[i][n-1] && grid[i][n-1] == 1)
            {
                dfs(i,n-1,grid,vis);
            }
        }

        // rows

        for(int j=0;j<n;j++)
        {
            // first row
            if(!vis[0][j] && grid[0][j] == 1)
            {
                dfs(0,j,grid,vis);
            }
            // last row
            if(!vis[m-1][j] && grid[m-1][j]==1)
            {
                dfs(m-1,j,grid,vis);
            }
        }

        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != vis[i][j])
                {
                    res++;
                }
            }
        }

        return res;
    }
};
