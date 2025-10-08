https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

So here is the problem solution:
1)Take Map like on which day lake was full (lake -> First day rain)
2)and also track the data structure which is 0's in the array (in this day we haave to dry atleast 1 lake)
3)Greedily  pick the closest(mini) empty after the rain


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        // example [1,2,0,2,0,1]
        // choose greedely to dry up

        int n = rains.size();

        unordered_map<int,int>mp; // lake -> First day rain
        set<int>st; // store zero days
        vector<int>ans(n,1);

        for(int i=0;i<n;i++)
        {
            int lake = rains[i];
            if(lake == 0)
            {
                st.insert(i); 
            }
            else
            {
                ans[i] = -1;

                if(mp.count(lake)) {
                    auto it = st.lower_bound(mp[lake]);

                    if(it == st.end())
                    {
                        return {};
                    }

                    int day = *it;
                    ans[day] = lake;

                    st.erase(it);
                }

                mp[lake] = i;
            }
        }

        return ans;
        
    }
};
