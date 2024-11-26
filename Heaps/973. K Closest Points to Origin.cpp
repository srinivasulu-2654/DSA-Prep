https://leetcode.com/problems/k-closest-points-to-origin/description/

***** This is a very imp question to tackle new challenge ******


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        // int n = points[0].size();

        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>maxi;

        for(int i=0;i<n;i++)
        {
            
                int val = points[i][0] * points[i][0] + points[i][1]*points[i][1];
                maxi.push({val,{points[i][0],points[i][1]}});

                if(maxi.size()>k) maxi.pop();
  
        }

        while(maxi.size() != 0)
        {
            pair<int,int>p = maxi.top().second;
            vector<int>temp;
            temp.push_back(p.first);
            temp.push_back(p.second);
            ans.push_back(temp);
            maxi.pop();
        }
        

        return ans;
    }
};
