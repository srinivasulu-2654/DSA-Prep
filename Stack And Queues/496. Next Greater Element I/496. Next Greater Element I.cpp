class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>nge_mp;
        stack<int>st;
        int i = n-1;
        while(i>=0)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }

            if(st.empty())
            {
                nge_mp[nums2[i]] = -1;
            }

            else nge_mp[nums2[i]] = st.top();

            st.push(nums2[i]);
            i--;
        }

        vector<int>res(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            res[i] = nge_mp[nums1[i]];
        }
        return res;
    }
};
