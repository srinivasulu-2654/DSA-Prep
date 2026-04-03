https://www.geeksforgeeks.org/problems/count-substring/1

class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n = s.size();
        int cnt = 0;
        vector<int>freq(3,0);
        int i=0,j=0;
        while(j<n)
        {
            freq[s[j] - 'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0)
            {
                cnt += n-j;
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        
        return cnt;
    }
};
