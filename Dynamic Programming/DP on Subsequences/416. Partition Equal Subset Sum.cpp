https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
bool f(vector<int>&nums,int ind,int target,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(ind==0) return nums[ind] == target;
    if(dp[ind][target] != -1) return dp[ind][target];

    bool take = false;
    if(nums[ind]<=target){
     take = f(nums,ind-1,target-nums[ind],dp);
    }
    bool notTake = f(nums,ind-1,target,dp);

    return dp[ind][target] =  take || notTake;
}
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++)  totalSum += nums[i];
        int target = totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(totalSum%2!=0) return false;
    
            return f(nums,n-1,target,dp);
        
    }
};
