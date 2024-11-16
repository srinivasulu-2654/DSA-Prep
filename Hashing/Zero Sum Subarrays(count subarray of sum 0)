 int findSubarray(vector<int> &arr) {
        // code here.
        
          int n = arr.size();
        unordered_map<int,int>mp;
        int sum = 0;
        int cnt = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(mp.find(sum) != mp.end())
            {
                cnt += mp[sum];
            }
            mp[sum]++;
        }
        
        return cnt;
     
    }
