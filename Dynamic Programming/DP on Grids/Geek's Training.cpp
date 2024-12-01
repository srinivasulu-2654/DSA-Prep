https://www.geeksforgeeks.org/problems/geeks-training/1

  int f(vector<vector<int>>&arr,int day,int last,vector<vector<int>>&dp)
  {
      
    //   int maxi = INT_MIN;
      if(day==0)
      {
          int maxi = 0;
          for(int i=0;i<3;i++)
          {
              if(i!=last) maxi = max(maxi,arr[0][i]);
          }
          
          return maxi;
      }
      
      if(dp[day][last] != -1) return dp[day][last];
      
      
      int total_points = 0;
      
      for(int i=0;i<3;i++)
      {
          if(i!=last)
          {
              int points = arr[day][i] + f(arr,day-1,i,dp);
              total_points = max(total_points,points);
          }
      }
      
      return dp[day][last] = total_points;
  }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(arr,n-1,3,dp);
    }

TC : O(n*4) * 3
SC : o(n) + o(n*4)
