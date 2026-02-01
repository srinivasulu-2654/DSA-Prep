class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int n = nums.size();
        int min_sum = nums[0];
        int firstMin = 51;
        int secondMin = 51;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<firstMin)
            {
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i]<secondMin)
            {
                secondMin = nums[i];
            }
        }
        return min_sum + firstMin + secondMin;

    }
};
