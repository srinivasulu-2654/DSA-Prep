/*
  https://leetcode.com/problems/two-furthest-houses-with-different-colors/?envType=daily-question&envId=2026-04-20
  -> so here bruete force just traverse with 2 for loops and then coming to optimal appraoch
  -> just for the 1st check from i = 0 colors[i] == colors[n-1] like this check i++ update maxi 
  -> same like this check i = n-1 colors[i] == colors[0] and update maxi 
*/


Bruete Force :

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
int n = colors.size();

for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        if(colors[i]==colors[j]) continue;
        else res = max(res,j-i);
    }
}

return res;
    }
};

Optimal Approach :

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();
        int maxi = 0;
        int i = 0;
        while(colors[i]==colors[n-1]) i++;
        maxi = max(maxi,abs(i-(n-1)));
        i = n-1;
        while(colors[0]==colors[i]) i--;
        maxi = max(maxi,abs(i-0));

        return maxi;
    }
};
