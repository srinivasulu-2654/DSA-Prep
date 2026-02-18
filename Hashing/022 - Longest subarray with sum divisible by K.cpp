https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1


 // User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        
        int n = arr.size();
        long long prefixSum = 0;
        unordered_map<int,int>mp;
        mp[prefixSum] = -1;
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            prefixSum += arr[i];
            int rem = ((prefixSum%k)+k)%k;
            if(mp.find(rem) != mp.end())
            {
                maxi = max(maxi,i-mp[rem]);
            }
            else mp[rem] = i;
        }
        
        return maxi;
    }
};
