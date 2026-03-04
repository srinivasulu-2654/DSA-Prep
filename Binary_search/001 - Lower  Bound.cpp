-> lower bound means smallest index where the element is greater than or equal to the target
-> then greater than or equal to means we are reducing the r = mid - 1 everytime we have to store the answer in this

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        int ans = n;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid]>=target)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
