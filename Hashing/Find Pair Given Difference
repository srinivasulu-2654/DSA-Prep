https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

Refer Day 8 1:08:12


  bool findPair(vector<int> &arr, int x) {
        // code here
        
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a = x + arr[i];
            
            // here we have to check both cases:
              // => a - b = x ==> 
                //  a = x + b (or) b = a - x
                
            if(mp.find(a) != mp.end() || mp.find(arr[i] - x) != mp.end())
            {
                return true;
                
            }
            
           
                mp[arr[i]] = 1;
            
        }
        
        return false;
    }
