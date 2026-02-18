https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

Refer Day 8 29:03

    TC : O(n)
    SC : O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        int sum = 0;
        mp[sum] = 1;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            int currRem = ((sum % k)+k)%k; // to handle negative integers
            if(mp.find(currRem) != mp.end())
            {
                cnt += mp[currRem];
                mp[currRem]++;
            }


            else{
                mp[currRem] = 1;
            }
        }

        return cnt;
    }
};
