https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-k-sorted-arrays


vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        vector<int>ans;
        
        priority_queue<int,vector<int>,greater<int>>mini;
        
        int m = arr.size();
        int n = arr[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mini.push(arr[i][j]);
                
                // if(mini.size()>K) 
                // {
                //     ans.push_back(mini.top());
                //     mini.pop();
                // }
            }
        }
        
        while(mini.size() != 0)
        {
            ans.push_back(mini.top());
            mini.pop();
            
        }
        
        
        return ans;
    }
