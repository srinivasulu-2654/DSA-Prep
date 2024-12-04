https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

   bool f(vector<int>&arr,int ind,int target,vector<vector<int>>&dp)
   {
    //   if(arr[ind]>target) return false;
       if(target == 0) return true;
       if(ind==0) return (arr[0]==target);
       
       if(dp[ind][target] != -1) return dp[ind][target];
       
       bool take = false;
       
      if(arr[ind]<=target){
      take =  f(arr,ind-1,target-arr[ind],dp);
      
      }
       bool nonTake = f(arr,ind-1,target,dp);
       
       return dp[ind][target] =  take | nonTake;
   }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(arr,n-1,target,dp);
        
        
    }
