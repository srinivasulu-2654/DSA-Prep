/*
  1. Bruete Force :

      first convert the number into binary then if there is only 1 set bit then it is power of 2

     2. Optimal approach

     bool isPowerOfTwo(int n) {

        if(n <= 0) return false;
        
        if((n & (n-1)) == 0) return true;
        else return false;
    }
*/
  
