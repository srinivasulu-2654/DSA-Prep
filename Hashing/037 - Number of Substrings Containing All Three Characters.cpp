https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

1st Approach :

class Solution {
public:

    int atmostK(string s, int k)
    {
        int n = s.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int cnt = 0;
        while(j<n)
        {
            mp[s[j]]++;

            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }

            cnt += j-i+1;
            j++;
        }

        return cnt;
    }
   
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int k = 3; // abc
        int total = 1LL * n*(n+1)/2;
        return total - atmostK(s,k-1); // k = abc => 3 total - atmost(k-1)
    }
};


2nd Appraoch : 
-> as we have only a,b,c k = 3 any way in that problem
-> they have asked like this in window size at least 3 characters of like a,b,c
-> so we can able to do like this 
-> s = "abcabc
  if i = 0,j=0 then our window will be like this abc now abca, abcab, abcabc also valid so then from that i we can able to calculate till
  like this cnt = cnt + n - right;

  -> after adding into the cnt like this then we have to move ith pointer to i++
  -> now the window size frequencey size will decrease to bc again add bca again calculate that's it


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int total = 0;
        int i = 0,j=0;
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;

        while(j<n)
        {
            if(s[j]=='a') cntA++;
            else if(s[j]=='b') cntB++;
            else cntC++;

            while(cntA> 0 && cntB > 0 && cntC > 0)
            {
                total += (n-j);
                if (s[i] == 'a') cntA--;
                else if (s[i] == 'b') cntB--;
                else cntC--;

                i++;

            }

            j++;
        }

        return total;
    }
};
