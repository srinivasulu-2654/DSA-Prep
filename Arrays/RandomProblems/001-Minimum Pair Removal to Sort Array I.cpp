https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/?envType=daily-question&envId=2026-01-22

class Solution {
public:
    
    int minPairSum(vector<int>&nums)
    {
        int minSum = INT_MAX;
        int index = -1;
        int n = nums.size();

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+nums[i+1] < minSum)
            {
                index = i;
                minSum = nums[i]+nums[i+1];
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        
        int cnt = 0;
        while(!is_sorted(begin(nums),end(nums))) {
            int ind = minPairSum(nums);
            nums[ind] = nums[ind]+nums[ind+1];
            nums.erase(begin(nums)+ind+1);
            cnt++;
        }

        return cnt;
    }


};
