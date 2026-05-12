https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/?envType=daily-question&envId=2026-05-12

class Solution {
public:

    bool isPosssible(vector<vector<int>>& tasks,int mid)
    {
        for(auto it:tasks)
        {
            int actual = it[0];
            int minimum = it[1];

            if(mid<minimum) return false;
            else mid = mid - actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
       sort(tasks.begin(),tasks.end(),
       [](vector<int>&a,vector<int>&b)
       {
            return (a[1]-a[0]) > (b[1]-b[0]);
       });
        int l = 0;
        int r = 1e9;
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(isPosssible(tasks,mid) == true)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};
