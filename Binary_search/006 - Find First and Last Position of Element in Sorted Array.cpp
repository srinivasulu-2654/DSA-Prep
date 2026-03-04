/*
  -> This is nothing but lower bound and upper bound
  -> if lb ans == n || nums[lb] != target return {-1,-1}
  -> res{lb,ub-1}
*/

class Solution {
public:
   
   int lower(vector<int>&nums,int target)
   {
        int n = nums.size();
        int l=0,r=n-1;
        int ans = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=target)
            {
                ans = mid;
                r = mid - 1;
            }

            else{
                l = mid + 1;
            }
        }

        return ans;
   }

    int upper(vector<int>&nums,int target)
   {
        int n = nums.size();
        int l=0,r=n-1;
        int ans = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>target)
            {
                ans = mid;
                r = mid - 1;
            }

            else{
                l = mid + 1;
            }
        }

        return ans;
   }

  
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower(nums,target);
        if(lb==nums.size() || nums[lb] != target) return {-1,-1};
        int ub = upper(nums,target) - 1;

        return {lb,ub};
    }
};
