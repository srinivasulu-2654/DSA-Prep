https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        
        int n = s.size();
        unordered_map<char,int>mp;
        int maxi = 0;
        int i = 0;
        int j = 0;
        while(j<n)
        {
            mp[s[j]]++;
            
            while(mp[s[j]]>1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            
            maxi = max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
    }
};
