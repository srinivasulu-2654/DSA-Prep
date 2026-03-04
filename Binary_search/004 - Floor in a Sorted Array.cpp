-> See in this problem they told to find the greatest index which is less than or equal to target
-> then store the ans in small to big type ( I mean from left to right)

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int ans = -1;
        int l = 0,r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(arr[mid]<=x)
            {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        
        return ans;
    }
};
