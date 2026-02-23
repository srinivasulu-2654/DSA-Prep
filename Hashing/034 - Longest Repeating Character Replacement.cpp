https://leetcode.com/problems/longest-repeating-character-replacement/description/

/*
so here also same exactly at most k means (<=k)
to replace we have to do these things for example:
  window size = 5 lets say then ABAAB k = 2
    then if we want to replace k characters to achieve longest substring na what we have to do
    -> windowSize - max freq element => 5 - 3 => 2 so k also 2 then we can able to replace */

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int maxi = 0;
        int i=0,j=0;
        unordered_map<char,int>mp;
        int maxFreq = 0;
        while(j<n)
        {
            mp[s[j]]++;
            maxFreq = max(maxFreq,mp[s[j]]);
            int currWindowLength = j-i+1; // everytime check window Size
            int val = currWindowLength - maxFreq; // here check wheather val < k then only we can replace k letters
            while(val>k && mp.size() != 0)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                val--;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
