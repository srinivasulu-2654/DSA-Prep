// here the concept is same like peak element 1

/*
  -> so here the thing is we have to go according column wise and in coloumn choose maximum element
  -> coz it should be greater compare to all the neighbours thus we are taking 
  -> so if mid > mid+1 eliminate right half else left half
*/

class Solution {
public:

    int findRowIndex(vector<vector<int>>& mat,int n,int m,int col)
    {
        int maxEle = -1;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col] > maxEle)
            {
                maxEle = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int l=0,h=m-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int maxRowIndex = findRowIndex(mat,n,m,mid);
            int left = mid-1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid+1 < m ? mat[maxRowIndex][mid+1] : -1;
            int val = mat[maxRowIndex][mid];
            if(val > left && val > right)
            {
                return {maxRowIndex,mid};
            }
            else if(val < left) h = mid-1;
            else l = mid+1;
        }

        return {-1,-1};
    }
};
