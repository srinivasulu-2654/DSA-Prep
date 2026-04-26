/*
  https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26
  -> Same like detect the cycles only but some slight changes that's it
*/

class Solution {
public:

    bool bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        // {r,c},{parent_row,parent_col}
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{row,col},{-1,-1}});

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int parent_row = it.second.first;
            int parent_col = it.second.second;

            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                   && grid[nrow][ncol] == grid[row][col])
                {
                    if(!vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow,ncol},{row,col}});
                    }
                    else
                    {
                       
                        if(nrow != parent_row || ncol != parent_col)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j])
                {
                    if(bfs(i,j,grid,vis)) return true;
                }
            }
        }

        return false;
    }
};
