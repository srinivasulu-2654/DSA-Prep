// Same like above problem only but there is some slight changes check once

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,-1);
        if(n==1) return {-1};
        // ans[n-1] = -1;
        int maxi = -1;
        for(int i=n-1;i>=0;i--)
        {
           ans[i] = maxi;
           maxi = max(maxi,arr[i]);
        }

        return ans;
    }
};
