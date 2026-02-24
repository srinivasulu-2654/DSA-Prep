//  Same as exactly k 

class Solution {
public:

    int countAtmostK(vector<int>&nums,int k)
    {
        int n = nums.size();
        int i=0,j=0;
        int cnt = 0;
        int oddCnt = 0;

        while(j<n)
        {
            if(nums[j]%2 != 0) oddCnt++;

            while(oddCnt>k)
            {
                if(nums[i]%2!=0) oddCnt--;
                i++;
            }

            cnt += j-i+1;
            j++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtmostK(nums,k) - countAtmostK(nums,k-1);
    }
};
