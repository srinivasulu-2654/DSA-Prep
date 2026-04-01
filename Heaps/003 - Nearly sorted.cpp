https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
    -> here we want to place the values in original place
    -> i mean k aslo given but the k will be in the place of that value to till k
    -> so take mini and put top into the arr
*/

    void nearlySorted(vector<int>& arr, int k) {
        // code
        
        priority_queue<int,vector<int>,greater<int>>mini;
        int j=0;
        
        for(int i=0;i<arr.size();i++)
        {
            mini.push(arr[i]);
            if(mini.size()>k)
            {
               arr[j] = mini.top();
                mini.pop();
                j++;
            }
        }
        
        while(mini.size() != 0)
        
        {
            arr[j] = mini.top();
            mini.pop();
            j++;
        }
        
    }
