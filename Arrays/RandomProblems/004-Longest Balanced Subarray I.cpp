https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int res = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_set<int>even;
            unordered_set<int>odd;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);

                if(even.size()==odd.size()) res = max(res,j-i+1);
            }
        }

        return res;
    }
};
