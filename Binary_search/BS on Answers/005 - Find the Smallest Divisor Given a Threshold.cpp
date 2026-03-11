// this question is same like koko eating bananas only

class Solution {
  public:
  
    int fun(vector<int>&arr,int mid,int k)
    {
        int totalSum = 0;
        for(int i=0;i<arr.size();i++)
        {
            totalSum += ceil((double)arr[i]/(double(mid)));
        }
        return totalSum;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        
        int n = arr.size();
        int ans = -1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
        }
        int low = 1,high = maxi;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int val = fun(arr,mid,k);
            
            if(val<=k)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;
    }
};
