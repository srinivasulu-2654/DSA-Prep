class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int cnt = 0;
        int n = s.size();
        if(n==1 && s[0]=='1') return true;
        int i = 0,j=i+1;

        while(i<n && j<n)
        {
            while(i<j && (s[i] == '1' && s[j] == '1'))
            {
                j++;
            }

          if(s[i] == '1' || s[j] == '1')  cnt++;

            i = j;
            j = j+1;
        }

        return cnt == 1 ? true : false;
    }
};
