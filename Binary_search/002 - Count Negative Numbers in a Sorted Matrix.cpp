https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28

class Solution {
public:

   int countNeg(vector<int>&col)
   {
      int n = col.size();
      int l = 0;
      int h = n-1;
      while(l<=h)
      {
         int mid = (l+h)/2;
         if(col[mid]<0)
         {
            h = mid - 1;
         }
         else l = mid + 1;
      }
      return n - l;
   }

    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
           cnt += countNeg(grid[i]);
        }

        return cnt;
    }
};


TC: n * log m
SC: O(1)
  
