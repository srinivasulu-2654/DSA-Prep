For this there is one simple logic that's it problem can be solved

atmost na - <=k
atleast na - >=k

for this we have to subtract from total - atmost(k) it will get the answer of atleast(k)

Refer Day - 6 from 1:13:06

https://www.lintcode.com/problem/1375/?fromId=349&_from=collection


class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */

     long long atmostk(string &s,int k)
     {
         int n = s.size();
    long long cnt = 0;
    unordered_map<char,int>mp;
    int i=0,j=0;
    int distinct = 0;
    while(j<n)
    {
        
        if(mp.find(s[j])!=mp.end()) 
        {
            mp[s[j]]++;
        }
        else{
            mp[s[j]] = 1;
            distinct++;
        }
        
        while(i<=j && distinct > k)
        {
            mp[s[i]]--;
            if(mp[s[i]] == 0)
            {
                distinct--;
                mp.erase(s[i]);
                
            }
            i++;
        }
        
        cnt += j-i+1;
        j++;
         
    }
    
    return cnt;
     }
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        long long n = s.size();
        return n*(n+1)/2 - atmostk(s,k-1);
    }
};
