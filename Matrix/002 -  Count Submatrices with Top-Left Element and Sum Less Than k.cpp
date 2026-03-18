https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18

/* 
    -> so we have to return the sum which <= k such that we have to return the matrices
    -> Bruete Force:
      -> so first take 2 loops to traverse matrix
      -> and then again run 2 internal for loop to run particularly from mat[0][0] to mat[i][j]
      -> but here doing repetative tasks againn and again

      Optimal approach:
      [[1,2,3],[4,5,6],[7,8,9]]
      -> whenever you have to find sum of submatrices in a grid, always go for this kind of approach
      -> But keep eye on corner case
      -> here for example if (i,j) => (1,2) then it will ask the sum to (i-1)(j) => (0,2)
      -> by the same way column wise (1,2) it will ask to (i,j-1)
      -> so here mat[i][j] += [i-1][j] + [i][j-1] => here 1+2+3   +   1+2+4+5 => here 1+2 adding twice so we have to do like this 
      -> so we have to remove the repetive adding elements so that mat[i][j] = [i-1][j] + [i][j-1] - [i-1][j-1] -> remove diagonally element
      -> [i-1][j-1] this will give the sum from [0][0] to [i-1][j-1] 
      -> 1 + 2 + 3 + 1 + 2 + 4 + 5 - 1 -2 => here one 1 will cancel one 2 will cancel then it will become
      -> 1 + 2 + 3 + 4 + 5 => 21 => just should ask to digonal
      -> I mean here if at a point (i,j) it will ask above row and from (i,j) it will ask same row but till before column and do minus 
         of (i-1,j-1) in both cases of row asking and col asking
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(i>0)  grid[i][j] += grid[i-1][j];
              if(j>0)  grid[i][j] += grid[i][j-1];
              if(i>0 && j>0)  grid[i][j] -= grid[i-1][j-1];

               if(grid[i][j] <= k)
               {
                    cnt++;
               }
               else{
                    break;
               }
            }
        }

        return cnt;
    }
};
