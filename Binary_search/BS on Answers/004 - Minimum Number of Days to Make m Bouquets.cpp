[1,10,3,10,2], m = 3, k = 2 here in this n < m*2 then this is not possible

[7 7 7 7 13 11 12 7] m = 2, k = 3 here in order to make atleast 1 flower bloom we have to minimum of the array
-> so the answer will be present in the min and max of the given array

Approach 1 :

class Solution {
public:

    bool isPossible(vector<int>&bloomDay,int day,int m,int k)
    {
        int cnt = 0;
        int noOfBlooms = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else {
               noOfBlooms += (cnt/k);
               cnt = 0; 
            }
        }

         noOfBlooms += (cnt/k); // this will handle the last k adjacent elements; [7 7 7 7 13 11 12 7] on 12 th day last 3 elemts will match condition so 11 12 7 also will count 
         if(noOfBlooms >= m) return true;
         return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if(n < m*k)  return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        for(int day=mini;day<=maxi;day++)
        {
            if(isPossible(bloomDay,day,m,k) == true)
            {
                return day;
            }
        }

        return -1;
    }
};

TC : O(maxi-mini) * N

Optimal Approach :

-> Here no need of taking the ans variable becuase we are using the opposite polarity

class Solution {
public:

    bool isPossible(vector<int>&bloomDay,int day,int m,int k)
    {
        int cnt = 0;
        int noOfBlooms = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else {
               noOfBlooms += (cnt/k);
               cnt = 0; 
            }
        }

         noOfBlooms += (cnt/k); // this will handle the last k adjacent elements;
         if(noOfBlooms >= m) return true;
         return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if(n < val)  return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
       
       int low = mini;
       int high = maxi;
       int ans = 0;
       while(low<=high)
       {
         int mid = (low+high)/2;

         if(isPossible(bloomDay,mid,m,k) == true)
         {
            ans = mid;
            high = mid - 1;
         }
         else low = mid + 1;
       }

        return ans;
    }
};

