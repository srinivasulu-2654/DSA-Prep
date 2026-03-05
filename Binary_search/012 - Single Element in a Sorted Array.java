Should solve this in O(log n) and O(1)

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
  
