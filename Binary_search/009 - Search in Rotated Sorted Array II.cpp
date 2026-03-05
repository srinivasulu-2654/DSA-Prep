-> So here in this problem duplicates contains so in this case we have to trim down the elements
-> for example if this the problem 
    [3 1 2 3 3 3 3] if it is like this dont know which is the sorted half so we have to trim down the same elements

Another perfect example :

0
1 0 1 1 1

  class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0,h=n-1;

        while(l<=h)
        {
            int mid = (l+h)/2;
            if(nums[mid] == target) return true;
            
            if(nums[l] == nums[mid] && nums[mid] == nums[h])
            {
                l++;
                h--;
            }
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target <= nums[mid])
                {
                    h = mid - 1;
                }
                else l= mid + 1;
            }

            else
            {
                if(nums[mid] <= target && target <= nums[h])
                {
                    l = mid + 1;
                }
                else h = mid - 1;
            }
        }

        return false;
    }
};
