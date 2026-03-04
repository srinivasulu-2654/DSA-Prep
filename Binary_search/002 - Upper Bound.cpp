-> Same as lower bound just simply slight change

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int ans = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid]>target)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};
