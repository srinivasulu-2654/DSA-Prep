For this there is one simple logic that's it problem can be solved

atmost na - <=k
atleast na - >=k

for this we have to subtract from total - atmost(k) it will get the answer of atleast(k)

Refer Day - 6 from 1:13:06

https://www.lintcode.com/problem/1375/?fromId=349&_from=collection

formula is we have to remove atmost k substring  from total substrings and k = k-1 (because exactly k we already taking in atleast right check number line once)

#include<bits/stdc++.h>
using namespace std;

int substrings_having_atleast_k_unique_characters(string &s,int k)
{
    int n = s.size();
    int cnt = 0;
    k -= 1; // becuase we have to elimnate the exact k substrings (i mean it will come already in atleast right)
    unordered_map<char,int>mp;
    int i=0,j=0;
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
    
    return n*(n+1)/2 - cnt;
}

int main()
{
    string str = "abcabcabcabc";
    int k = 3;
    cout<<substrings_having_atleast_k_unique_characters(str,k-1);
    return 0;
}
