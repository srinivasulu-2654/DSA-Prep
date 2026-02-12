
// This is kind of prefixSum

For this problem (kadanes algorithm) we have to cover lot of corner cases

for example if we don't intialize prefixsum = 0 in map as 

mp[ps] = -1

why  because refer this example  : 

4
-1 1 -1 1

and example [0] 

unordered_map<int,int>mp;
        int maxi = 0;
        int sum = 0;
        int ps = 0;
        mp[ps] = -1;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            
            if(mp.find(sum) != mp.end())
            {
                maxi = max(maxi,i-mp[sum]);
            }
            
            else {
            
            mp[sum] = i;
            }
        }
        
        return maxi;
