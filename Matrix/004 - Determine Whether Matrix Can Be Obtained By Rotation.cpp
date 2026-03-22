https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22

/*
  -> this problem is exactly rotate image problem only
  -> so we have to rotate 90 degrees that means:
      -> Transpose and reverse of every row
  -> so here to achieve target matrix we can able to rotate untill 4 times only
  -> 90 degrees x 4 = 360 degrees
*/

class Solution {
public:

    void rotate(vector<vector<int>>& mat)
    {
        int n = mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i = 0;i<n;i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size();

        for(int times = 1;times<=4;times++)
        {
            bool isEqual = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                {
                    if(mat[i][j] != target[i][j])
                    {
                        isEqual = false;
                        break;
                    }
                }

                if(!isEqual) break;
            }

            if(isEqual) return true;

            rotate(mat);
        }

        return false;
    }
};
