/*
  -> take 2 string as example:
    s = x a d c
    t = b a b t
    so here now 2 charceters can map to same letter thus here taking 2 maps
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        int m = s.size();
        for(int i=0;i<m;i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            if(mp1.find(c1) != mp1.end() && mp1[c1] != c2) return false;
            if(mp2.find(c2) != mp2.end() && mp2[c2] != c1) return false; 
            mp1[c1] = c2;
            mp2[c2] = c1;
        }  

        return true; 
    }
};
