/* https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

-> Same as leetcode No : 542 */

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        
        int m = grid.size();
        int n = grid[0].size();
        // {{r,c},dist}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
                else vis[i][j] = 0;
            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow <m && ncol>=0 && ncol<n && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = distance+1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
        
        return dist;
    }
};
