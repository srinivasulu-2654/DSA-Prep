/* 
  -> so same we can't solve this as same like previous problem
  -> but we can pass individual column and we can return the index of the target element
  -> so coming to optimal approach we can start from row = 0, col = n-1 
  -> so from downwards we can predict element is there becuase all are increasing order
  -> so from leftwards(from col=n-1) we can say ele is there all are decreasing order
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0,col = m-1; // will start from row = n-1,col = 0;

        while(row<n && col >= 0)
        {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }

        return false;
    }
};
