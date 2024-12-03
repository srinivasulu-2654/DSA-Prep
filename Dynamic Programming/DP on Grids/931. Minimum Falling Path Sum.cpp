https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        
       for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];

       for(int i=1;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
            int leftDia = INT_MAX;
            if(j-1>=0) leftDia =  matrix[i][j] + dp[i-1][j-1];
             int up =  matrix[i][j] + dp[i-1][j];
             int rightDia =  INT_MAX;
             if(j+1<m) rightDia =  matrix[i][j] + dp[i-1][j+1];

             int temp =  min(leftDia,up);
            dp[i][j] = min(temp,rightDia);
          }
       }

        int mini = dp[m-1][0];
        for(int j=1;j<n;j++)
        {
            mini = min(mini,dp[n-1][j]);
        }

        return mini;
    }
};
