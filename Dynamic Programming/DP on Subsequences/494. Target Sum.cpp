https://leetcode.com/problems/target-sum/

This problem is same as like a partions with give difference try to check DP - 18 problem


class Solution {
public:
    
      int f(vector<int>&arr,int ind,int k,vector<vector<int>>&dp){
  
  if(ind==0)
  {
      if(k==0 && arr[0] == 0) return 2;
      if(k ==0 || arr[0] == k) return 1;
      return 0;
  }
    
    if(dp[ind][k] != -1) return dp[ind][k];
       
       int take = 0;
      if(arr[ind]<=k) take = f(arr,ind-1,k-arr[ind],dp);
      int nonTake = f(arr,ind-1,k,dp);
      
      return dp[ind][k] =  take + nonTake;
  }

    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        
        int totalSum = 0;
        for(auto it:arr)  totalSum += it;
        
        if(totalSum - target < 0 || (totalSum - target) % 2 !=0 ) return 0;
        
        int s2 = (totalSum - target) / 2;
        
        vector<vector<int>>dp(n,vector<int>(s2+1, -1));
        
        return f(arr,n-1,s2,dp);
    }
};
