https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01

class Solution {
public:

   bool fun(int n, vector<int>& batteries, long long mid)
   {
      long long target = n * mid;
      long long sum = 0;

      for(int i = 0; i < batteries.size(); i++)
      {
          sum += min((long long)batteries[i], mid);
          if(sum >= target) return true;
      }
      return false;
   }
   
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long total = 0;
        for(int i = 0; i < batteries.size(); i++)
        {
            total += batteries[i];
        }

        long long low = 1, high = total / n;  
        long long maxi = 0;

        while(low <= high)
        {
            long long mid = (low + high) / 2;

            if(fun(n, batteries, mid))  
            {
               maxi = mid;
               low = mid + 1;               
            }
            else 
            {
                high = mid - 1;
            }
        }

        return maxi;
    }
};
