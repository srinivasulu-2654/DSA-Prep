/*
  -> Allocate minimum pages
  -> Split Array Largest Sum
  -> The Painter's Partition Problem-II

  These 3 problems are same to same like as we already solved the Allocate minimum pages
*/

class Solution {
public:
    int canAllocate(vector<int> &arr, int k,int pages)
    {
        int cntStudents = 1;
        int pageCount = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] + pageCount <= pages)
            {
                 pageCount += arr[i];
            }
            else
            {
                cntStudents++;
                pageCount = arr[i];
            }
        }
        
        return cntStudents;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        
        
        int n = arr.size();
        if(k > n) return -1;
        int maxi = *max_element(arr.begin(),arr.end());
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        
        int low = maxi,high = sum;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int students = canAllocate(arr,k,mid);
            if(students > k)
            {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};
