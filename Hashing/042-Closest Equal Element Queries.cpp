
https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
       int n = nums.size();
       unordered_map<int,vector<int>>mp;
       vector<int>res;
       int q =  queries.size();
       for(int i=0;i<n;i++)
       {
          mp[nums[i]].push_back(i);
       }
       for(int q:queries){
            int ele = nums[q];
           vector<int> &vec = mp[ele];
           int sz = vec.size();
           if(sz==1)
           {
                res.push_back(-1);
                continue;
           }
           int pos = lower_bound(vec.begin(),vec.end(),q) - vec.begin();
           int temp = INT_MAX;

           // right nearest
           int right = vec[(pos+1)%sz];
           int d = abs(q-right);
           int circularDist = n-d;
           temp = min({temp,d,circularDist});

           //left nearest/neighbour
           int left = vec[(pos-1+sz)%sz];
            d = abs(q-left);
            circularDist = n-d;
           temp = min({temp,d,circularDist});

           res.push_back(temp);
       }

       return res;
    }
};
