https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03

// So stringstream is a buffer which is used to append the string without using that much extra space

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        stringstream res;
        // res<<" ";
        int spaceind = 0;
        for(int i=0;i<s.size();i++)
        {
            if(spaceind<spaces.size() && i == spaces[spaceind]) {
                res<<" ";
                spaceind++;
            }
            res<<s[i];
        }

        return res.str();
    }
};
