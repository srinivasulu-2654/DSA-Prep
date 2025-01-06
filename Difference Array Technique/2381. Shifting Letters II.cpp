https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();

        vector<int>diff(n,0);

        // buid the diff array;

        for(auto &query : shifts)
        {
            int l = query[0];
            int r = query[1];
            int dir = query[2];

            int x;

            if(dir==0)
            {
                x  =  -1;

            }
            else  x = 1;

            diff[l] += x;
            if(r + 1 < n)
            {
                diff[r+1] -= x;
            }
        }

        // find the cummulative sum to find the resultant change in i;

        for(int i = 1;i<n;i++)
        {
            diff[i] =  diff[i-1] + diff[i];
        }

        // apply the shift 

        for(int i=0;i<n;i++)
        {
            int shift = diff[i] % 26;  // to wrap the 26 alphabets

            if(shift<0)
            {
                shift += 26;  // to wrap the 26 alphabets -- to neglect neg value
            }

            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }

        return s;
    }
};
