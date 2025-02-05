https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
   
   int daysReq(vector<int>&weights,int cap)
   {
      int n = weights.size();
      int days = 1,load = 0;
      for(int i=0;i<n;i++)
      {
          if(load + weights[i] > cap)
          {
              days = days + 1;
              load = weights[i];
          }
          else{
             load += weights[i];
          }
      }

      return days;
   }
   
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
           maxi = max(maxi,weights[i]);
           sum += weights[i];
        } 

        int l = maxi,r = sum;
        int ans = -1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = daysReq(weights,mid);
            if(val<=days)
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;

    }
};

TC : O(n x log(sum))
