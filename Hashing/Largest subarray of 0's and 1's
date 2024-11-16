This problem is same like as Largest Subarry with 0 sum 
but only thing is we have to change all 0's into -1 then calculate the size if the sum comes 0;

 int maxLen(vector<int> &arr) {
        // Your code here
        
        // this problem is same as largest subarray with sum 0;
        
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            arr[i] = -1;
        }
        
        int maxi = 0;
        unordered_map<int,int>mp;
        
        int ps = 0;
        mp[ps] = -1;
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            
            if(mp.find(sum) != mp.end())
            {
                maxi = max(maxi,i-mp[sum]);
            }
            
            else mp[sum] = i;
            
        }
        
        return maxi;
