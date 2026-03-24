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
