/* 
    -> This will be works for 8 directions but we want only 4 directions
    
     for(int delrow = -1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                
                   int nrow = row + delrow;
                   int ncol = col + delcol;
                   
                   if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                        && grid[nrow][ncol] == '1' && vis[nrow][ncol] != 1)
                   {
                      vis[nrow][ncol] = 1;
                      q.push({nrow,ncol});
                   }
                }
            }
*/

class Solution {
public:

    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vis[row][col] = 1;
        q.push({row,col});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i =0;i<4;i++)
            {
                   int nrow = row + delrow[i];
                   int ncol = col + delcol[i];
                   
                   if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                        && grid[nrow][ncol] == '1' && vis[nrow][ncol] != 1)
                   {
                      vis[nrow][ncol] = 1;
                      q.push({nrow,ncol});
                   }
                
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }

        return cnt;
    }
};
