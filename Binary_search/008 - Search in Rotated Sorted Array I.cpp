/*
  -> if mid == target then return stariaght away
  -> or else check for half sorted wheather it is left or right
  -> in that also should check :
      nums[l] <= target && target <= nums[mid] then h = mid-1
      else l = mid+1
    -> same like above do for the right part also 

    nums[] = [7 8 9 1 2 3 4 5 6] target = 1
*/

class Solution {
    int search(int[] arr, int key) {
        // code here
        
        int n = arr.length;
        int l = 0,r = n-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(arr[mid]==key) return mid;
            
            // check for half sorted
            
            if(arr[l]<=arr[mid])
            {
                if(arr[l]<=key && key<=arr[mid])
                {
                    r = mid-1;
                }
                else l = mid+1;
            }
            else
            {
                if(arr[mid]<=key && key<=arr[r]){
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        
        return -1;
    }
}
