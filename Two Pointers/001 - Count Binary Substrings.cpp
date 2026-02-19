https://leetcode.com/problems/count-binary-substrings/?envType=daily-question&envId=2026-02-19

// Here we have to track prev and curr that's it

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0;
        int curr = 1;
        int cnt = 0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                curr++;
            }
            else 
            {
                cnt += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }

        cnt += min(prev,curr); // to cover the last case also
        return cnt;
    }
};
