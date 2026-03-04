class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
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
