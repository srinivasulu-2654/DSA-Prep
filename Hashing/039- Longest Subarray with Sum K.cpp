https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

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
