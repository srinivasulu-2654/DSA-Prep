/*
  Bruete Force:

  int countSetBits(int n) {
        // code here
        
        int cnt = 0;
        
        for(int i=1;i<=n;i++)
        {
            int x = i;
        
        while(x > 0)
        {
            if(x%2 == 1) cnt += 1;
             x = x/2;
        }
    }
        
        return cnt;
    }

  -> Actually tha above code is to count set bits from 1 to n
 
  1. Here actually for odd numbers na the last bit bit will be for sure 1 only 
  2. if we check for 13 = 8 + 4 + 1
  3. so here to remainder 1 we can do for n & 1 because for even na 14 %2 = 0 no use of incrementing count and if it is 13 na 1101 & 1 it will give 1
  4. for n = n/2 dividing we can do right shift operator n >> 1 => n/2
*/
