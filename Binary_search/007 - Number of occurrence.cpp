/* 
    -> same find lower bound index and upper bound index then do uppper - 1 (first thing)
    -> then do upper - lower + 1; -> it will come length 
*/

class Solution {
  public:
   
   int first(vector<int>&arr,int target)
   {
       int n = arr.size();
       int l = 0,r=n-1;
       int ans = n;
       
       while(l<=r)
       {
           int mid = (l+r)/2;
           
           if(arr[mid]>=target)
           {
               ans = mid;
               r = mid - 1;
           }
           
           else l = mid + 1;
       }
       
       return ans;
   }
   
   int last(vector<int>&arr,int target)
   {
       int n = arr.size();
       int l = 0,r=n-1;
       int ans = n;
       
       while(l<=r)
       {
           int mid = (l+r)/2;
           
           if(arr[mid]>target)
           {
               ans = mid;
               r = mid - 1;
           }
           
           else l = mid + 1;
       }
       
       return ans;
   }
   
   
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int a = first(arr,target);
        
        if(a == arr.size() || arr[a] != target) return 0;
        
        int b = last(arr,target) - 1;
        
        return b - a + 1;
        
    }
};
