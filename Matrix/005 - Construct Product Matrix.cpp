https://leetcode.com/problems/construct-product-matrix/?envType=daily-question&envId=2026-03-24

Bruete Force Approach :

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        long long prod = 1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                prod *= grid[i][j];
            }
        }

        vector<vector<int>>res(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long val = (prod/grid[i][j]) % 12345;
                res[i][j] = val;
            }
        }

        return res;
    }
};

Optimal Approach : 

/* 
  -> at a normal point [1 2 3 4 5] at point of 3 except 3 reaming should multiply na 
  -> will multiply left and right side of ele's of 3
  -> so for that we can take prefix and sufix array's and do just product of left side and right side ele's
  -> so here instead of maintaing the prefix and suffix matrix we can first calculate the suffix matrix firstly and then
  -> we can calculate the prefix in air itself:
     suffix[i] = suffix[i] * prefix
     prefix = prefix*arr[i];
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>suffixProd(m,vector<int>(n,0));

        long long suffix = 1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                suffixProd[i][j] = suffix;
                suffix = (suffix*grid[i][j]) % mod;
            }
        }

        long long prefix = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                suffixProd[i][j] = (prefix*suffixProd[i][j])%mod;
                prefix = (prefix*grid[i][j]) % mod;
            }
        }

        return suffixProd;
    }
};
