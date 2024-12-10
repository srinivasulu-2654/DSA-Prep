https://www.geeksforgeeks.org/problems/rod-cutting0840/1

It is same as unbounded knsapsack problem

  int f(vector<int>&price,int ind,int cap,vector<vector<int>>&dp)
  {
      if(ind==0)
      {
          return cap * price[0];   // because last guy has only lenght 1 so for cap = 12 then 1 * price[0]
      }
      
      if(dp[ind][cap] != -1) return dp[ind][cap];
      
      int notTake = f(price,ind-1,cap,dp);
      int take = INT_MIN;
      int rodLength = ind+1;
      
      if(rodLength<=cap) take = price[ind] + f(price,ind,cap-rodLength,dp);
      
      return dp[ind][cap] =  max(notTake,take);
  }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(price,n-1,n,dp);
    }
