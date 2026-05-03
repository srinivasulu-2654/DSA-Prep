class Solution {
public:

    bool checkPrime(int n)
    {
        if(n<=1)  return false;

        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0) return false;
            }
        return true;
    }
    
    int reverseNum(int n)
    {
        int num = n;
        int rev = 0;
        while(num!=0)
            {
                int rem = num%10;
                rev = rev*10 + rem;
                num = num/10;
            }
        return rev;
    }
    
    int sumOfPrimesInRange(int n) {
        int sum = 0;
        int rev = reverseNum(n);
        // if(rev == n) return 0;
        int maxi = max(rev,n);
        int mini = min(rev,n);
        for(int i=mini;i<=maxi;i++)
            {
                if(checkPrime(i)==true)
                {
                    sum = sum + i;
                }
            }
        return sum;
    }
};
