/* 

here for any given n = 4 or n = something then lenght will be 2^n - 1

so if n = 4, k = 3
            then n = 3, k = 3 same bacause k = 3 is half of the lenght before appending the 1 to the string
            will call recursive function for fun(n-1,k)

            if(k < len/2){
                solve(n-1,k) // call this recursion function
            }

           else if(k == ceil(len/2)) then blindly we can return '1' becuase we are appending 1 right

           else if(k > len / 2) now this is second part after appending 1 

           then 0111001 1 0110001 now:

           1 - 7th bit
           2 - 6th bit  => total len - (bit no - 1) => 7 - (2-1) => 6
           3 - 5th bit 
        */

class Solution {
public:
    char findKthBit(int n, int k) {

        if(n==1) return '0';

        int len = pow(2,n) - 1;

        if(k < ceil(len/2.0)){
            return findKthBit(n-1,k); // previous sn bit will be same before concating '1'
        }
        else if(k == ceil(len/2.0)){
            return '1'; // exactly middel
        }
        else{
            char ch = findKthBit(n,len-(k-1));
            return (ch=='0') ? '1' : '0'; // flipped bit
        }
    }
};
