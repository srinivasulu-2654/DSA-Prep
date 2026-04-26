https://leetcode.com/problems/surrounded-regions/description/

/*
    -> Similar like "Rotten Oranges"
    -> Here the main logic is we have to set 'O' to 'X' with all the borders
    -> so instead exploring all the inside things we have to explore only it's boundaries
    -> and then just traverse if vis[i][j] == 0 then do this grid[i][j] = 'X'

    “Time complexity is O(mn) since each cell is visited once, and space is O(mn) due to visited array and recursion stack.”

*/

class Solution {
public:

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis)
    {
         int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                dfs(nrow,ncol,board,vis);
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i = 0; i < m; i++)
            {
                
                if(!vis[i][0] && board[i][0] == 'O')
                    dfs(i, 0, board, vis);

                if(!vis[i][n-1] && board[i][n-1] == 'O')
                    dfs(i, n-1, board, vis);
            }

        for(int j = 0; j < n; j++)
        {
            
            if(!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);

           
            if(!vis[m-1][j] && board[m-1][j] == 'O')
                dfs(m-1, j, board, vis);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
