We have to find peak element nums[i-1]<nums[i]<nums[i+1]

Base case :
 if(n==1) return 0;
        if(nums[0]>nums[1]) return 0; // already nums[-1] < nums[0]
        if(nums[n-1]>nums[n-2]) return n-1; // already nums[n-1] > nums[n] 
Normal Answer :
 arr[] = [1 2 3 4 5 6 7 8 5 1] 
 if nums[mid] > nums[mid-1]  // elimate left half
 else elimante right half

Code :

int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0; // already nums[-1] < nums[0]
        if(nums[n-1]>nums[n-2]) return n-1; // already nums[n-1] > nums[n] 
        int l = 1, h=n-2;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1]) l = mid + 1;
            else h = mid - 1;
        }

        return -1;
