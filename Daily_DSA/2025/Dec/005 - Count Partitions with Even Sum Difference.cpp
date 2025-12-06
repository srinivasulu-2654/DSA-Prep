https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05

Approach -1 :

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];

        int leftSum = 0;
        int i = 0;
        while(i<n-1)
        {
            leftSum += nums[i];
            int rightSum = sum - leftSum;
            if((rightSum-leftSum) % 2 == 0) ans++;
            // else tempSum = 0;
            i++;
        }

        return ans;
    }
};

Approach 2:

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        /*
          x + y = s
          x - y = ?
          x - (s-x)
          2x - s
          here 2 * anything even (even - even) alwasy even

        */

        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        for(int i=0;i<n-1;i++)
        {
            int tempSum = 2 * nums[i] - sum;
            if(tempSum % 2 == 0) ans++;
        }

        return ans;
    }
};
