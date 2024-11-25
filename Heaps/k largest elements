https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

   vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        
        priority_queue<int,vector<int>,greater<int>>mini;
        int n = arr.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            mini.push(arr[i]);
            
            if(mini.size()>k)
            {
                mini.pop();
                
            }
            
        }
        
        while(mini.size()!=0)
        {
            ans.push_back(mini.top());
            mini.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
