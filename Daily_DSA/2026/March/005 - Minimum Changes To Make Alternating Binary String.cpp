class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();
        int i = 0,j=1;
        int cnt = 0;

        while(i<n && j<n)
        {
            while(i<j && s[i] != s[j])
            {
                i++;
                j++;

                if(j == n) return cnt;
            }

            if(s[i] == '0') s[j] = '1';
            else s[j] = '0';

            cnt++;

            i++;
            j++;
        }

        return cnt;
    }
};

this code will fail becuase greedily we are replacing the things but we want min operations  (Greedy Approach will fail)

-> Example : 10010100 -> ans = 3 but our will return 5


Now real approach :

so the answer will be either 01010101... or else 1010101...
-> 01010101 -> even places 0 and odd places 1
-> 101010101 -> even places 1 and odd places 0

  class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();
        int start_0 = 0;
        int start_1 = 0;

        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                if(s[i] != '0') start_0++;
                if(s[i] != '1') start_1++;
            }
            else
            {
                if(s[i] != '0') start_1++;
                if(s[i] != '1') start_0++;
            }
        }

        return min(start_0,start_1);
    }
};
