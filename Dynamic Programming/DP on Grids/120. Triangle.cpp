https://leetcode.com/problems/triangle/description/

class Solution {
public:

   int f(vector<vector<int>> &triangle,int i,int j,vector<vector<int>>&dp)
   {
      int n = triangle.size();
      if(i==n-1) return triangle[i][j];

      if(dp[i][j] != -1) return dp[i][j];

      int down =triangle[i][j] +  f(triangle,i+1,j,dp);
      int dia =triangle[i][j] +  f(triangle,i+1,j+1,dp);

      return dp[i][j] =  min(down,dia);
   }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(triangle,0,0,dp);
    }
};
