https://leetcode.com/problems/find-k-closest-elements/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        priority_queue<pair<int,int>>maxi;   // we are using maxi heap because we have to eliminate the maximum diff of (nums[i] - x)
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            maxi.push({abs(arr[i] - x),arr[i]});

            if(maxi.size()>k)
            {
                maxi.pop();
            }
        }

        while(maxi.size() > 0)
        {
            auto it = maxi.top();
            ans.push_back(it.second);
            maxi.pop();
        }

       sort(ans.begin(),ans.end());
       return ans;
    }
};
