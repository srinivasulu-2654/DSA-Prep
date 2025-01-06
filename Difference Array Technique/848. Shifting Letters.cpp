https://leetcode.com/problems/shifting-letters/description/


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n = s.size();

        for(int i = n-2;i>=0;i--)
        {
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
            if(shifts[i] < 0) shifts[i] += 26;
        }

        for(int i=0;i<n;i++)
        {
            // takeout value from this

            int shift = shifts[i] % 26;

            // add the value to the shifts
            
            if(shift < 0) shift += 26;

            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';

        }

        return s;
    }
};
