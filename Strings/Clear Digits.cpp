https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10

class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;
        int n = s.size();
        for(char ch:s)
        {
            if(isalpha(ch))
            {
                st.push(ch);
            }
            else if(isdigit(ch))
            {
                if(!st.empty()) st.pop();
            }
        }

        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};

TC : O(n)
SC : O(n)
