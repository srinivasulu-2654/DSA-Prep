class Solution {
    public int findKRotation(int arr[]) {
        // Code here
        
        int n = arr.length;
        int low = 0,high = n-1;
        int ans = Integer.MAX_VALUE;
        int ind = 0;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(arr[low]<=arr[high])
            {
                if(arr[low]<ans)
                {
                    ind = low;
                    ans = arr[low];
                }
                
                break;
            }
            
            else if(arr[low]<=arr[mid])
            {
                if(arr[low]<ans)
                {
                    ind = low;
                    ans = arr[low];
                }
                
                low = mid + 1;
            }
            
            else
            {
                if(arr[mid]<ans)
                {
                    ind = mid;
                    ans = arr[mid];
                }
                
                high = mid-1;
            }
        }
        
        
        
        return ind;
    }
}
