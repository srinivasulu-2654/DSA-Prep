/*
    -> so here main thing is above diagonal how many zeros are required to make the diagonal all with 1's
    -> so for that we have to calculate this formula => (n-row-1) -> this will get the required no. of zeros
    -> for that we have to calculate the endZeros for each row 
    -> and then swap based on the each row requirement
*/


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int totalSteps = 0;
        vector<int>endZeros(n,0);
        for(int i=0;i<n;i++)
        {
            int j = n-1;
            int cnt = 0;
            while(j>=0 && grid[i][j]==0)
            {
                cnt++;
                j--;
            }
            endZeros[i] = cnt;
        }

        for(int i =0;i<n;i++)
        {
            int required = n-i-1;

            int j = i;
            while(j<n && endZeros[j]<required)
            {
                j++;
            }

            if(j==n) return -1;

            totalSteps += j-i;

            while(j>i)
            {
                swap(endZeros[j],endZeros[j-1]);
                j--;
            }
        }

        return totalSteps;
    }
};
