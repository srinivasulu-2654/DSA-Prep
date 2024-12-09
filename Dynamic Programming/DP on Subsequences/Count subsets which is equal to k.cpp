https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
  
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(arr,n-1,target,dp);
    }
};

