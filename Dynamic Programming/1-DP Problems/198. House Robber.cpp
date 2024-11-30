Memoization:

class Solution {
public:
    
    int f(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind<0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + f(nums,ind - 2,dp);
        int nontake = f(nums,ind-1,dp);

        return dp[ind] =  max(take,nontake);
    }
    
     int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return f(nums,n-1,dp);
    }
};

TC : O(N)
SC : O(N) + O(N)

Tabulation :

class Solution {
public:
    

    
     int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
           if(i>1)  take += dp[i-2];
            int nonTake = dp[i-1];
            dp[i] = max(take,nonTake);
        }
        return dp[n-1];
    }
};


TC:O(N)
SC : O(n)
