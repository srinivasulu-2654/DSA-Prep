https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08


Bruete Force :

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n = words.size();

        int cnt = 0;

        for(int i=0;i<n-1;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(words[j].size() >= words[i].size())
                {
                     if(words[j].find(words[i]) == 0 && words[j].rfind(words[i]) == words[j].size() - words[i].size())
                     {
                        cnt++;
                     }
                }
            }
        }

        return cnt;
    }
};


TC : O(n^2 * L)
SC : (n * L)   Temporary variables used in find() and rfind(), which are independent of 
