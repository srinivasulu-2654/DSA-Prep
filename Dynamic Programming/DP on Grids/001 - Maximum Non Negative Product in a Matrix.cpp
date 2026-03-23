https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23

/* 
  -> same like minimum path sum 
  -> if it will give only positive elements then it's fine but here they given negative ele's also
  -> so single path wont be sufficient
  -> for example if we take this example:

  [[1,-2,3],[1,4,-2],[2,3,4]]

  -> we we take this path 1->1->2->3->4 
  -> 1->-2->4->-2->4 
  -> compare with these which path will give more na that only we have to choose

  -> here for example at 1 particular point if we return max(-96,48) na we will return 48 to previous point but in that point if there will -1 na then 
     answer will come wrong right so we have to take track of minVal and maxVal at each and every point

  -> dry run for these examples:
  [[1,2],[3,4]] and [[-1,2],[3,1]]

  -> so observe every corner of the test case
*/

class Solution {
public:
    
    int m, n;
    typedef long long ll;
    int mod = 1e9+7;
    vector<vector<pair<ll,ll>>> dp;

    pair<ll,ll>fun(int i,int j,vector<vector<int>>& grid)
    {
        if(i==m-1 && j == n-1) return {grid[i][j],grid[i][j]};

        if(dp[i][j].first !=LLONG_MIN)
        {
            return dp[i][j];
        }

        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;

        ll val = grid[i][j];


        if(i+1 < m){
        auto down = fun(i+1,j,grid);
            if(down.first!=LLONG_MIN)
            {
            
                maxi = max(maxi,max(val*down.first,val*down.second));
                mini = min(mini,min(val*down.first,val*down.second));
            }
        }

        if(j+1<n){
             auto right = fun(i,j+1,grid);
            if(right.first!=LLONG_MIN)
            {
                maxi = max(maxi,max(val*right.first,val*right.second));
                mini = min(mini,min(val*right.first,val*right.second));
            }
        }

        return dp[i][j] =  {maxi,mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN, LLONG_MAX}));
        auto res = fun(0,0,grid);
        ll ans = res.first;
        if(ans < 0) return -1;

        return ans % mod;
    }
};
