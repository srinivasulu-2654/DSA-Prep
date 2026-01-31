class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // [2,1,5,4,3,0,0]

        int n = nums.size();

        // 1. Find break point which is nums[i] < nums[i+1];
        int index = -1;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // 2. find the element for which nums[index] < greater ele (slightly greater ele)

        for(int i=n-1;i>index;i--)
        {
            if(nums[index] < nums[i])
            {
                swap(nums[index],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
    }
};
