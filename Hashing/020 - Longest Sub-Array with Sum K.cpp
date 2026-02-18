https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


  int lenOfLongestSubarr(vector<int>& nums, int k) {
        // code here
        
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        int maxi = 0;
        mp[0] = -1;
        int sum  = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(mp.find(sum-k) != mp.end())
            {
                maxi = max(maxi,i-mp[sum-k]);
                
            }

            if(mp.find(sum) == mp.end()) mp[sum] = i;
 
            
        }
      return maxi;
    }
