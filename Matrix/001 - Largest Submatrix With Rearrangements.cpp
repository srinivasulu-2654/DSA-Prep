https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2026-03-17

/*
  -> so the problem is we have to exchange the coloumns only so that we have to return the maximum areas of 1's
  -> for that we have to calculate current matrix[i][j] = 1 in that above if 1 is there na we have calucalte based on the above 1's 
  -> and current should = curr 1 + above 1's
  -> sort decending order and there by we have to calucalte the area
  -> height = current legnth of 1's and base will be i + 1
  -> Area = height * width

  Steps :
  1. count the consecutive 1's => row
  2. sort descending order wise
  3. area max
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(matrix[row][col] == 1 && row > 0)
                {
                    matrix[row][col] += matrix[row-1][col];
                }
            }

            vector<int>heights = matrix[row];
            sort(heights.begin(),heights.end(),greater<int>());

            for(int i=0;i<n;i++)
            {
                int height = heights[i];
                int base = (i+1);
                maxArea = max(maxArea,height*base);
            }
        }

       
        return maxArea;
    }
};
