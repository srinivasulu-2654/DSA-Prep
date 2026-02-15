https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    // Write your code here

    int n = str.size();
    int maxi = 0;
    unordered_map<char,int>mp;
    int i=0,j=0;
    while(j<n)
    {
        mp[str[j]]++;
        while(mp.size()>k)
        {
            mp[str[i]]--;
            if(mp[str[i]]==0) mp.erase(str[i]);
            i++;
        }

        maxi = max(maxi,j-i+1);
        j++;
    }

    return maxi;
}


