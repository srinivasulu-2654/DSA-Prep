https://www.naukri.com/code360/problems/subarrays-with-equal-0-s-1-s-and-2-s_2825370?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
int countSubarrays(int n, vector<int> arr) {
    
    int cnt = 0;
    int z1 = 0,z2=0,z0=0;
    unordered_map<string,int>mp;
    mp["0#0"] = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) z0++;
        else if(arr[i]==1) z1++;
        else z2++;

        string exp = to_string(z1-z0) + "#" + to_string(z2-z1);
        if(mp.find(exp) != mp.end())
        {
            cnt += mp[exp];
            mp[exp]++;
        }
        else mp[exp] = 1;
    }

    return cnt;
}
