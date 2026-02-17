https://leetcode.com/problems/subarray-sum-equals-k/description/

Prefix sum 

Refer Day 7 1:31

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0] = 1;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(mp.find(sum-k) != mp.end())
            {
                cnt += mp[sum-k];
                
            }

            if(mp.find(sum) != mp.end()) mp[sum]++;
 
            else mp[sum] = 1;
        }
      return cnt;
    }
};
