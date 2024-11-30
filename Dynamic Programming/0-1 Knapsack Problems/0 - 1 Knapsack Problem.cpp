https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


Recursive Method :

int f(int capacity,vector<int>&val,vector<int> &wt, int n)
    {
        if(n==0 || capacity==0) return 0;
        
        if(wt[n-1] <= capacity) {
            
            return max(val[n-1] + f(capacity - wt[n-1], val,wt,n-1), f(capacity,val,wt,n-1));
        } 
        
        else {
            
            return f(capacity,val,wt,n-1);
        }
        
        
    }
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = wt.size();
        return f(capacity,val,wt,n);
    }

TC : O(2^n)
SC : O(n) - recursive stack calls


Memoiazation - Top - Down : (we have to create a 2-D vector which stores randomly changing values) 

int f(int capacity,vector<int>&val,vector<int> &wt, int n,vector<vector<int>>&dp)
    {
        if(n==0 || capacity==0) return 0;
        
        if(dp[n][capacity] != -1) return dp[n][capacity];
        
        if(wt[n-1] <= capacity) {
            
        return dp[n][capacity] =  max(val[n-1] + f(capacity - wt[n-1], val,wt,n-1,dp), f(capacity,val,wt,n-1,dp));
        } 
        
        else {
            
            return dp[n][capacity] =  f(capacity,val,wt,n-1,dp);
        }
        
        
    }
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
         int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
        // int n = wt.size();
        return f(capacity,val,wt,n,dp);
    }
