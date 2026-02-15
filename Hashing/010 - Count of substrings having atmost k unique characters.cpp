// there is no question link for this

so here for count the number of substrings also we did sometimes like this:
    cnt++;
    cnt += j-i+1

    1st logic is for when we follow bruete force and
    2nd logic is for when we follow optimal approach

Bruete force approach : 

#include<bits/stdc++.h>
using namespace std;

int substrings_having_atmost_k_unique_characters(string &s,int k)
{
    int n = s.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        unordered_map<char,int>mp;
        for(int j=i;j<n;j++)
        {
             mp[s[j]]++;
            
            if(mp.size()>k)
            {
                break;
            }
            
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    string str = "aabcdb";
    int k = 2;
    cout<<substrings_having_atmost_k_unique_characters(str,k);
    return 0;
}

Optimal approach:

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
