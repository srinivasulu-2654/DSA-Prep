// Try this problem also for sure

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int i=0,j=0;
        int zerocnt = 0;
        while(j<n)
        {
            if(nums[j]==0) zerocnt++;

            while(zerocnt>k)
            {
                if(nums[i]==0) zerocnt--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};
