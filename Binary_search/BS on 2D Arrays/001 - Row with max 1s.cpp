https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

Bruete Force :

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int m = arr.size();
        int n = arr[0].size();
        
        int maxCnt = 0;
        int index = -1;
        
        for(int i=0;i<m;i++)
        {
            int cntRow = 0;
            for(int j=0;j<n;j++)
            {
                cntRow += arr[i][j];
            }
            
            if(cntRow > maxCnt)
            {
                maxCnt = cntRow;
                index = i;
            }
        }
        
        return index;
    }
};


Optimal Approach :

// User function template for C++
class Solution {
  public:
  
    int lowerBound(vector<int>& arr, int n, int target) {
        // code here
        
        // int n = arr.size();
        int ans = n;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid]>=target)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int m = arr.size();
        int n = arr[0].size();
        
        int maxCnt = 0;
        int index = -1;
        
        for(int i=0;i<m;i++)
        {
            int onesCnt = n -  lowerBound(arr[i],n,1);
            if(onesCnt > maxCnt)
            {
                maxCnt = onesCnt;
                index = i;
            }
        }
        
        return index;
    }
};
