https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10

class Solution {
public:
   
    int dp[1001][1001];
    
    int solve(int i,int j,string &s1,string &s2)
    {
         int m = s1.size();
        int n = s2.size();

        if(i>=m && j>=n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i>=m) return s2[j] + solve(i,j+1,s1,s2);
        if(j>=n) return s1[i] + solve(i+1,j,s1,s2);

        if(s1[i]==s2[j])
        {
            return solve(i+1,j+1,s1,s2);
        }

        int takes1 = s1[i] + solve(i+1,j,s1,s2);
        int takes2 = s2[j] + solve(i,j+1,s1,s2);

        return dp[i][j] =  min(takes1,takes2);
    }

    int minimumDeleteSum(string s1, string s2) {
      
       for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++) {
            dp[i][j] = -1;
        }
       }
       return solve(0,0,s1,s2);
    }
};

Recursion: TC : O(exponential time)
Dp TC : O(m*n)
