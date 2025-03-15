// Same like as Koko eating bananas

https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14

class Solution {
public:

   long long equalDistribute(vector<int>& candies, long long mid)
   {
      long long cnt = 0;
      for(int i=0;i<candies.size();i++)
      {
          cnt += candies[i]/mid;
      }
      return cnt;
   }

    int maximumCandies(vector<int>& candies, long long k) {
        long long ans = 0;
        int n = candies.size();
        int maxiCandi = 0;
        for(int i=0;i<n;i++)
        {
            maxiCandi = max(maxiCandi,candies[i]);
        }

        int l = 1,h = maxiCandi;
        while(l<=h)
        {
            int mid = (l+h)/2;
            long long val = equalDistribute(candies,mid);
            if(val >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return ans;
    }
};
