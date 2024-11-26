https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        priority_queue<pair<int,int>>maxi;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        for(auto it : mp)
        {
            maxi.push({-it.second,it.first});
        }

        while(maxi.size() != 0)
        {
            auto it = maxi.top();
            int freq = it.first;
            for(int i=1;i<=abs(freq);i++) ans.push_back(it.second);
            maxi.pop();
        }

      
       return ans;
    }
};
