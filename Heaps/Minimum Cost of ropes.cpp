https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


   int minCost(vector<int>& arr) {
        
        int n =arr.size();
        int cost = 0;
        priority_queue<int,vector<int>,greater<int>>mini;
        
        for(int i=0;i<n;i++)
        {
            mini.push(arr[i]);
        }
        
        while(mini.size()>=2)
        {
            int first = mini.top();
            mini.pop();
            int second = mini.top();
            mini.pop();
            cost = cost + first + second;
            
            mini.push(first+second);
        }
        
        return cost;
    }
