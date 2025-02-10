https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

Approach 1 :

 void rotateArr(vector<int>& arr, int d) {
        // code here
        
        int n = arr.size();
        d = d % n;
        vector<int>temp;
        for(int i=0;i<d;i++) temp.push_back(arr[i]);
        
        for(int i=d;i<n;i++)
        {
            arr[i-d] = arr[i];
        }
        
        for(int i=n-d;i<n;i++)
        {
            arr[i] = temp[i-(n-d)];
        }
    }
