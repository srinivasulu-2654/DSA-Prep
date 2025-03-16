vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n,-1);
        stack<int>st;
        int i = n-1;
        while(i>=0)
        {
            
            while(!st.empty() && arr[i]>=st.top())
            {
                st.pop();
            }
            
            
            if(st.empty())
            {
                nge[i] = -1;
            }
            
            else nge[i] = st.top();
            
            st.push(arr[i]);
            
            i--;
        }
        
        return nge;
    }
