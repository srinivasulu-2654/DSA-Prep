class Solution {
    public boolean isSorted(int[] arr) {
        // code here
        
        int cnt = 0;
        int n = arr.length;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1]) cnt++;
        }
        
        if(cnt==0) return true;
        if(cnt==1 && arr[0]>arr[n-1] || cnt==1 && arr[0] == arr[n-1]) return true;
        
        return false;
    }
}
