https://leetcode.com/problems/max-consecutive-ones/description/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxi = 0;
        int currcnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                currcnt++;
                maxi = max(maxi,currcnt);
            }
            else currcnt = 0;

        }

        return maxi;
    }
};
