#include<bits/stdc++.h>
using namespace std;

int substrings_having_atmost_k_unique_characters(string s,int k)
{
    int n = s.size();
    int cnt = 0;
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
        
        while(i<j && distinct > k)
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

int main()
{
    string str = "aabcbcabba";
    int k = 2;
    cout<<substrings_having_atmost_k_unique_characters(str,k);
    return 0;
}
