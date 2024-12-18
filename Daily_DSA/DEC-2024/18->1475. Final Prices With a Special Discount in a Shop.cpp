https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=daily-question&envId=2024-12-18

This can used by sloving monotonic stack:

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        stack<int>st;
        for(int i=0;i<n;i++){
        while(!st.empty() && prices[st.top()] >= prices[i])
        {
            prices[st.top()] -= prices[i];
            st.pop();
        }

        st.push(i);
      }

      return prices;
    }
};
