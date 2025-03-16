https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

class Solution {
public:
    
    long long canRepair(vector<int>& ranks,long long mid)
    {
        // here we have to find no. of cars

        long long cnt = 0;
        for(int i = 0;i<ranks.size();i++)
        {
            // here we have to find numbers of cars 
            // time = r * n^2
            // so we already know time(mid), rank and we have to find n
            // n = sqrt(time/r)

            // long long temp = (long long)mid/ranks[i];

            cnt += sqrt((long long)mid/ranks[i]);
        }
        return cnt;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
        int n = ranks.size();
        long long ans = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,ranks[i]);
        }

        long long  l = 1, r = (long long)maxi * cars * cars; // time taken to repair all the cars;

        while(l<=r)
        {
            long long  mid = (l+r)/2;
            if(canRepair(ranks,mid) >= cars) 
            {
                ans = mid;
                r = mid - 1;
            }

            else l = mid + 1;
        }

        return ans;
    }
};
