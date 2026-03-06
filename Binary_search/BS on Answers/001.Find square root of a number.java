Approachs:
1. normal use Math.sqrt(x)
2. Linear Approach:
    for(int i=1;i<=n;i++)
      if(i*i<=n) ans = i;
      else break
3. Binary search:

// so here l = 1 and h = n now do the calculation

class Solution {
    int floorSqrt(int n) {
        // code here
        
        int l = 1;
        int h = n;
        
        int ans = 1;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(mid*mid <= n)
            {
                ans = mid;
                l = mid+1;
            }
            
            else h = mid - 1;
        }
        
        return ans;
    }
}
