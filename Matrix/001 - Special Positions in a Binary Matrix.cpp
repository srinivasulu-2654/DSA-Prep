Approach 1:

class Solution {
public:

    bool checkRow(vector<vector<int>>& mat,int row)
    {
        int cnt = 0;
        for(int j=0;j<mat[0].size();j++)  // check here same row diff col
        {
            if(mat[row][j]==1) cnt++;
        }

        return cnt == 1;
    }

    bool checkCol(vector<vector<int>>& mat,int col)
    {
        int cnt = 0;
        for(int i=0;i<mat.size();i++)  // check here same col diff row
        {
            if(mat[i][col]==1) cnt++;
        }

        return cnt == 1;
    }

    int numSpecial(vector<vector<int>>& mat) {
        
        int cnt = 0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && checkRow(mat,i) && checkCol(mat,j))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

Appraoch 2:

class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int cnt = 0;

        int rowCnt[] = new int[m];
        int colCnt[] = new int[n];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1){
                    if(rowCnt[i]==1 && colCnt[j]==1)
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
}
