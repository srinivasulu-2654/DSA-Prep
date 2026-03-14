https://leetcode.com/problems/kth-missing-positive-number/description/

/*

1. Bruete Force Approach :

-> 5 6 10 12 if k = 4 na then ans = 4
-> if k = 6 na  1 2 3 4 5 6 7 ans = 7
-> so nums[i] < k na it will take place so increase k++
-> if nums[i] > k then return k

*/

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i] <= k) k++;
            else break;
        }
        
        return k;
    }
};

Approach 2 : (optimal approach)

-> here normal binary search is not applicable 
-> also we can not apply BS on answers also  -> here wa have to return min or max like that so here numbers are missing
-> this case is very different

-> here we have to figure out near by indexes

/* 
  [2 3 4 7 11] k = 5
  ideally the numbers will be look like this 1 2  3 4 5 so in 7 th place of nums 7 - 4 = > 3 numbers are missing

   so if in case arr[] = [4 7 9] k = 3 so here at last high = -1 and low = 0

  here we are finding the no. of missing numbers in each index so that  low = 0, high = n-1; mid = if mid = 3  then 7 - 4 = 2 missing = in that index 2 elements (1 and 5)

  then ans = arr[high] + more elems (2 more )
  => arr[high] + (k - (arr[high] - high - 1)
  => high + k + 1
*/

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        int low = 0,high = n-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            int missing = arr[mid] - (mid+1); // 0 based index right
            
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return high + k + 1;
    }
};
