/*
  https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
  -> So it is same as the "Number of Islands"
  -> but the thing is we have to store the shape of the island there by we can store the unique values in set
  1 1 0 1 1
  1 0 0 0 0 
  0 0 0 1 1
  1 1 0 1 0

  -> so here there are the points like this (0,0), (1,0),(0,1)
  -> so same shape having in this (2,3), (3,3), (2,4) => so acheive above point just minus the base (2,3)
  -> (2,3) - (2,3) = > (0,0)
  -> (3,3) - (2,3) => (1,0)
  -> (2,4) - (2,3) => (0,1)

  => that's it we can get the number of distince islands
  => so here the only thing is wheather u explore bfs or dfs just go in same pattern
  => so here we are storing the shape of the island 

   TC : O(n x m) x log(m x n) + O(n x m x 4)
             first part is for loop with set store and second is exploring dfs
        SC : O(n x m) + O(n x m)
  
*/


// User function Template for C++

class Solution {
  public:
  
   void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,
        vector<pair<int,int>> &vec,int baserow,int basecol)
   {
       int m = grid.size();
       int n = grid[0].size();
       vis[row][col] = 1;
       vec.push_back({row-baserow,col-basecol});

       int delrow[] = {-1,0,1,0};
       int delcol[] = {0,1,0,-1};
       for(int i=0;i<4;i++)
       {
           int nrow = row + delrow[i];
           int ncol = col + delcol[i];
           
           if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
           {
               
               dfs(nrow,ncol,grid,vis,vec,baserow,basecol);
           }
       }

       return;
   }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
