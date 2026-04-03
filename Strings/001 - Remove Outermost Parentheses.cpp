class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string res = "";
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(cnt == 0) cnt++;
            else
            {
                if(s[i]=='(')
                {
                    cnt++;
                    res += s[i];
                }
                else
                {
                    cnt--;
                    if(cnt!=0) res += s[i];
                }
            }
        }

        return res;
    }
};
