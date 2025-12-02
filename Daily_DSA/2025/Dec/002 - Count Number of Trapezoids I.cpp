-> so here the only thing is we have to form the "horizontal trapezoid"
-> for this if there is y1 point na (. . . .) so how many horizantal lines will come na 4c2 = 4/2 * 3/1 = 6 lines
-> so for the next y2 point also same if there 5 points 5c2
-> so how many "horizontal trapezoid" na we have multiply like this (Horizantal line of y1) * (Horizantal line of y2)
-> if y3 also there then sum the total lines ob y1 + y2 and multiply with the result i mean (y+y2) * y3
-> becuase y4 points also makes vertical lines with y3 also y2 also y1 also 

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int m = 1e9+7;
        unordered_map<int,int>mp; // y - count

        for(auto &point : points)
        {
            int y = point[1];
            mp[y]++;
        }

        long long res = 0; // count of horizontal trapezoid
        long long prevHorizontalLines = 0;

        for(auto &it:mp)
        {
            int count = it.second;
            long long horizontalLines = (long long)count * (count-1) / 2; // countC2 formula
            res += horizontalLines * prevHorizontalLines;
            prevHorizontalLines += horizontalLines;
        }

         return res % m;
    }
};
