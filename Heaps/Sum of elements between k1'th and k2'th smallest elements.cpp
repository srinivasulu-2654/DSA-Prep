https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/0


    long long kthsmallest(long long arr[],long long n, long long k)
    {
        priority_queue<long long>maxi;
        
        for(int i=0;i<n;i++)
        {
            maxi.push(arr[i]);
            if(maxi.size()>k) maxi.pop();
        }
        
        return maxi.top();
    }
    
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        long long sum =0;
        long long first = kthsmallest(A,N,K1);
        long long second = kthsmallest(A,N,K2);
        
        for(int i=0;i<N;i++)
        {
            if(A[i]>first && A[i]<second)
            {
                sum += A[i];
            }
        }
        
        return sum;
       
    }
