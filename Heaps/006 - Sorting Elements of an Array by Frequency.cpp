https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

/*
    [9,2,1,1,1,2,4,4,5]  
        9 - 1
        2 - 2
        1 - 3
        4 - 2
        5 - 1
        
        so here if we take maxi na it will store first {2,4} and then {2,2} -> but we want 2 first and then 4 
        so here max heap will fail if we take min heap will check now:
        9 - -1
        2 - -2
        1 - -3    so first will store {-3,1} then {-2,2} and then {-2,4} now will get correct answer
        4 - -2
        5 - -1
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
    vector<int> fun(vector<int>&nums)
    {
        int n = nums.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        
        for(auto it:mp)
        {
            pq.push({-it.second,it.first});
        }
        
        vector<int>ans;
        
        while(!pq.empty())
        {
            int freq = pq.top().first;
            for(int i=0;i<abs(freq);i++) ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        
        Solution obj;
        vector<int>res = obj.fun(nums);
        for(int num:res)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
  
