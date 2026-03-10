class Solution {
  public:
  
  int f(int mid,int n,int m)
  {
      long long power =1;
      
      for(int i=0;i<n;i++)
      {
          power *= mid;
          
          if(power > m) return 2;
      }
      
      if(power == m) return 1;
      
      return 0;
  }
  
  
    int nthRoot(int n, int m) {
        // Code here.
        
        int l = 1,r = m;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            int ansFn = f(mid,n,m);
            
            if(ansFn == 1) return mid;
            
            else if(ansFn == 0) l = mid + 1;
            
            else r = mid - 1;
            
        }
        
        return -1;
    }
};
