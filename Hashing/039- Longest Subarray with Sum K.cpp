https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

Subarray Sum Equals K -> same this model but need to return count

Code 1 :

This code only works for all positive integers example: vector<int> nums = {10, 5, 2, 7, 1, 9};
but for negative integers it wont work we should do only code 2 : [10, 5, 2, 7, 1, -10], k = 15

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
       int n = arr.size();
       int maxi = 0;
       int i=0,j=0;
       int currSum = 0;
       while(j<n)
       {
           currSum += arr[j];
           
           while(currSum>k)
           {
               currSum -= arr[i];
               i++;
           }
           
           if(currSum == k) maxi = max(maxi,j-i+1);
           j++;
       }
       
       return maxi;
    }
};

Code 2 : 

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        int prefixSum = 0;
        unordered_map<int,int>mp;
        mp[prefixSum] = -1;
        int maxi = 0;
        int i = 0;
        
        while(i<n)
        {
            prefixSum += arr[i];
            if(mp.find(prefixSum-k) != mp.end())
            {
                maxi = max(maxi,i-mp[prefixSum-k]);
            }
            
            if(mp.find(prefixSum) == mp.end()) 
            {
                mp[prefixSum] = i;
            }
            
            i++;
            
        }
        
        return maxi;
    }
};
