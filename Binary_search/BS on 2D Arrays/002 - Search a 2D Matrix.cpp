/*
    -> other than this solution just faltten the 2D matrix in single array imagine
    -> l = 0, h = m*n-1 (just imagination) -> think it in a brain
    -> also we have to get to know row and col based on mid
    -> we have to convert 1D coordiate into 2D coordinate that's it our job is done
    -> row = mid/m
    -> col = mid%m -> here m means length of coloumn 
    -> so here 1st col i mean 0th col having multiples of 4 if n = 3, m = 4
    -> thus mid / m will get row
    -> col => mid % m
*/

// Bruete Force

class Solution {
public:

    bool isPresent(vector<int>&nums,int target)
    {
        int n = nums.size();
        int l = 0,h=n-1;
        while(l<=h)
        {
            int mid = (l+h)/2;

            if(nums[mid] == target) return true;
            else if(nums[mid]>target) h = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            bool isFound = isPresent(matrix[i],target);
            if(isFound == true) return true;
        }
        return false;
    }
};

// Optimal Approach :
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0,h=(m*n)-1;


        while(l<=h)
        {
             int mid = (l+h)/2;
             int row = mid/m;
             int col = mid%m;

             if(matrix[row][col] == target) return true;
             else if(matrix[row][col] >= target) h = mid - 1;
             else l = mid + 1;
        }

        return false;
    }
};
