Memoization :

class Solution {
public:
    int f(vector<int>&nums,int ind,int end,vector<int>&dp)
    {
        if(ind<end) return 0;
        if(ind==end) return nums[ind];

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + f(nums,ind-2,end,dp);
        int non = f(nums,ind-1,end,dp);

        return dp[ind] =  max(take,non);
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);

        int a = f(nums,n-1,1,dp);
        int b = f(nums,n-2,0,dp1);

        return max(a,b);
    }
};


Tabulation :

