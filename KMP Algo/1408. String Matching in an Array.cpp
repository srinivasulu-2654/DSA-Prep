https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        set<string>st;
        vector<string>ans;

        int n = words.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                if(words[j].find(words[i]) != string::npos)
                {
                    st.insert(words[i]);
                }
            }
        }
        ans.assign(st.begin(),st.end());
        return ans;
        
    }
};
