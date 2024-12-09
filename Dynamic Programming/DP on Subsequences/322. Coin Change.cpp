https://leetcode.com/problems/coin-change/description/


class Solution {
public:
   
   int f(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp)
   {
       if(ind==0)
       {
         // // why here checking na if coins[0] = 6, amount = 7 we cannot able to select we can't able to take in fractions 
          if(amount%coins[0] == 0) return amount/coins[0];  
           return 1e9;
       }

       if(dp[ind][amount] != -1) return dp[ind][amount];

       int notTake = 0 + f(coins,amount,ind-1,dp);
       int take = INT_MAX;
       if(coins[ind]<=amount) take = 1 + f(coins,amount - coins[ind],ind,dp);

       return dp[ind][amount] =  min(take,notTake);
   }

    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans = f(coins,amount,n-1,dp) ;
       if(ans >= 1e9) return -1;
       return ans;
    }
};
