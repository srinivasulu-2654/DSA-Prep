class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>nge(n,-1);
        int i = 2*n-1;
        while(i>=0)
        {
            while(!st.empty() && st.top() <= nums[i%n])
            {
                st.pop();
            }
           
           if(i<n)
           {
              nge[i] = st.empty() ? -1 : st.top();
           }
           st.push(nums[i%n]);
           i--;
        }

        return nge;
    }
};
