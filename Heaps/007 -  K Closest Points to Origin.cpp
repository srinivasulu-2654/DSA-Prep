https://leetcode.com/problems/k-closest-points-to-origin/description/

/* 
    ***** This is a very imp question to tackle new challenge ******
    -> here we want to return the closest points to origin i mean (0,0)
    -> sqrt((x1-x2)^2 + (y1-y2)^2) any way (x1,y1) => (0,0) sqrt(x1 sqaure + x2 square) 
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>>maxi;
        for(int i=0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int val = x*x + y*y;
            maxi.push({val,{x,y}});

            if(maxi.size()>k) maxi.pop();
        }
        vector<vector<int>>ans;
        while(maxi.size()!=0)
        {
            auto it = maxi.top().second;
            ans.push_back({it.first,it.second});
            maxi.pop();
        }
        return ans;
    }
};

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
