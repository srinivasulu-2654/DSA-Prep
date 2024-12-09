https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference


Here just modify some changes compare to previous problem 

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
  
  
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        int n = arr.size();
        
        int totalSum = 0;
        for(auto it:arr)  totalSum += it;
        
        if(totalSum - d < 0 || (totalSum - d) % 2 !=0 ) return 0;
        
        int target = (totalSum - d) / 2;
        
        vector<vector<int>>dp(n,vector<int>(target+1, -1));
        
        return f(arr,n-1,target,dp);
    }
