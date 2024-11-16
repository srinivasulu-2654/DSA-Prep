https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

 vector<int> countDistinct(int k, vector<int> &arr) {
        // code here
        
        vector<int>ans;
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n = arr.size();
        while(j<n)
        {
            mp[arr[j]]++;
            
            if(j-i+1<k) j++;
            else if(j-i+1==k)
            {
                ans.push_back(mp.size());
                mp[arr[i]]--;
                
                if(mp[arr[i]]==0) {
                    mp.erase(arr[i]);
                }
                
                i++;
                j++;
                
            }
        }
        
        return ans;

}

Time complexity : O(n)
Space Complexity : O(k)
