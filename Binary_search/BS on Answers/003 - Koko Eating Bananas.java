class Solution {

    int hourlyTimeTaken(int hourly,int [] piles)
    {
        int totalTime = 0;
        for(int i=0;i<piles.length;i++)
        {
            totalTime += Math.ceil((double)piles[i]/hourly);
        }
        return totalTime;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int maxi = Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            maxi = Math.max(maxi,piles[i]);
        }

        int l = 1;
        int r = maxi;
        int ans = 0;

        while(l<=r)
        {
            int mid = (l+r)/2;
            int timeTaken = hourlyTimeTaken(mid,piles);
            if(timeTaken<=h)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }

        return ans;
    }
}

Tc : O(n) * O(log (max))
