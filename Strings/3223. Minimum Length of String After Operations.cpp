/* https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

Thought Process :

Input: s = "abaacbcbb"

Output: 5



1) For given string we have to store their frequency in a container so that we get to know the frequency of every char

2) Here simple logic is there to tally for s[i] char to left and right there should be 3 same characters 

3) Then if we got temp[i] = 9 it means we have to delete every 2 chars that means 9-2 = 7-2 = 5-2 = 3-2 = 1

Hence finally,

temp[i] >= 3 and temp[i] % 2 == 1 then cnt += 1
temp[i] >= 3 and temp[i] % 2 == 0 then cnt += 2  temp[i] = 6 - 2 = 4 - 2 = 2 cnt += 2
cnt += temp[i] = 2 then cnt+ =2
 
return cnt; */

Code : 

class Solution {
public:
    int minimumLength(string s) {
        
        // unordered_ma<char,int>mp;

        int n = s.size();
        int cnt = 0;
        vector<int>temp(26,0);
        for(int i=0;i<n;i++)
        {
            temp[s[i] - 'a']++;
        }

        for(int i=0;i<26;i++)
        {
             if(temp[i] >= 3 && temp[i] % 2 == 1)
             {
                  cnt += 1;
             }

             else if(temp[i] >= 3 && temp[i] % 2 ==0)
             {
                cnt += 2;
             }

             else cnt += temp[i];
        }

        return cnt;

    }
};
