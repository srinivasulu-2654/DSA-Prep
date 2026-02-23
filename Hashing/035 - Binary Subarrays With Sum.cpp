https://leetcode.com/problems/binary-subarrays-with-sum/description/

// -> Same as Subarrays sum is equal to the K

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        unordered_map<int,int>mp;
        int prefixSum = 0;
        mp[prefixSum] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            prefixSum += nums[i];

            if(mp.find(prefixSum-goal) != mp.end())
            {
                cnt += mp[prefixSum-goal];
            }
            
            if(mp.find(prefixSum) != mp.end()) mp[prefixSum]++;
            else mp[prefixSum] = 1;
        }

        return cnt;
    }
};
