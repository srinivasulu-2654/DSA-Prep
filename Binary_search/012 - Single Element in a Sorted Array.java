Should solve this in O(log n) and O(1)

  This is a unique pattern that we have to notice 


to find single ele there are many cases :

   1.all the eles stored in (even,odd) then I am on the  left half -> then element is on right half so eliminate left half
   2. if all the eles stored in (odd,even) then I am on the  right half -> then element is on left half so eliminate right half
Cases we have to check are :
   mid % 2 == 1 && nums[mid] == nums[mid-1] || mid % 2 == 0 && nums[mid] == nums[mid+1] l = mid + 1

int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int l = 1,r=n-2;
        while(l<=r)
        {
           int mid = (l+r)/2;
           if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
           if((mid%2==1 && nums[mid] == nums[mid-1]) ||
           (mid%2==0 && nums[mid] == nums[mid+1])) l = mid + 1;
           else r = mid - 1;
        }

        return -1;

    }

  // Approach 1:
  use hasing like
  
  // Approach 2:
  use traversing for loop

  class Solution {
    int single(int[] arr) {
        // code here
        
        int n = arr.length;
        if(n==1) return arr[0];
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(arr[i] != arr[i+1]) return arr[i];
            }
            else if(i== n-1)
            {
                if(arr[i] != arr[i-1]) return arr[i];
            }
            else
            {
                if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
                {
                    return arr[i];
                }
            }
        }
        
        return 0;
        
    }
}
  
  Approach 3:
  use Binary Search

    Example : [1 1 2 2 3 3 4 5 5 6 6]
    -> totally depends upon (even,odd) (odd,even) indexes

class Solution {
    int single(int[] arr) {
        // code here
        
        int n = arr.length;
        
        if(n==1) return arr[0];
        
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        
        int l = 1,h=n-2;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            
            else if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 ==0 && arr[mid] == arr[mid+1])) l = mid + 1;
            else h = mid-1;
        }
        
        return -1;
    }
}
  
