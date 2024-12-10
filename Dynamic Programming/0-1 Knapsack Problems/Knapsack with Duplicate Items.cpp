https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items


// check for base case and all

class Solution {
  public:
  
  int f(vector<int>&val,vector<int>&wt,int cap,int ind,vector<vector<int>>&dp)
  {
      
      if(ind==0) 
      {
          return (cap/wt[ind]) * val[ind];
      }
      
      if(dp[ind][cap] != -1) return dp[ind][cap];
      
      int notTake = f(val,wt,cap,ind-1,dp);
      int take = INT_MIN;
      if(wt[ind]<=cap) take = val[ind] + f(val,wt,cap-wt[ind],ind,dp);
      
      return dp[ind][cap] =  max(notTake,take);
  }
  
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(val,wt,capacity,n-1,dp);
    }
