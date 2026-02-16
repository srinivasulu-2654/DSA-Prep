https://leetcode.com/problems/subarrays-with-k-different-integers/description/

Leetcode 992 

class Solution {
public:
    
    int calculateAtmostK(vector<int>&nums,int k)
    {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n)
        {
            mp[nums[j]]++;

            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }

            cnt += j-i+1;
            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return calculateAtmostK(nums,k) - calculateAtmostK(nums,k-1);
    }
};
