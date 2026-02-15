https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Bruete Force Approach : 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxi = 0;

        for(int i = 0; i < n; i++)
        {
            vector<int> freq(128, 0);

            for(int j = i; j < n; j++)
            {
                unsigned char ch = s[j];
                freq[ch]++;

                if(freq[ch] > 1)
                    break;

                maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};

Optimal Approach :

int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_map<char,int>mp;
        int maxi = 0;
        int i=0,j=0;
        while(j<n)
        {
            while(i<j && mp.find(s[j]) != mp.end())
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            mp[s[j]] = 1;
            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
