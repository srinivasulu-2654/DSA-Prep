class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i] - i;
        }

        unordered_map<int,int>mp;

        mp[nums[0]] = 1;

        for(int j = 1;j<n;j++)
        {
            int totalPairs = j;
            int goodPairs = mp[nums[j]];
            int badPairs = totalPairs - goodPairs;

            cnt += badPairs;

            mp[nums[j]]++;
        }

        return cnt;
    }
};
