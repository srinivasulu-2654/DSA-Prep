https://leetcode.com/problems/top-k-frequent-elements/description/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        for(int i=0;i<n;i++) mp[nums[i]]++;

       for(auto it:mp)
       {
          mini.push({it.second,it.first});
          if(mini.size()>k) mini.pop();
       }

       while(mini.size() != 0)
       {
          auto it = mini.top();
          ans.push_back(it.second);
          mini.pop();
       }

       return ans;
    }
};
