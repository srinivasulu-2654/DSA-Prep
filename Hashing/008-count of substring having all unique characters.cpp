-> There is no link for this problem

// Bruete force : // (so here we are wasting the traversals becuase if i in 0 and j in 1 a = 2 times so that whole substring wont be the 
// answer coz it will contains duplicates (so traversing and all no use) so here came the concept of sliding window.


String s = "aabcbcdbca" output = 24

#include<bits/stdc++.h>
using namespace std;

bool isunique(vector<int>&freq)
{
    for(int i=0;i<26;i++)
    {
        if(freq[i]>1) return false;
    }
    
    return true;
}

int substringshavingunique(string &s)
{
    int n = s.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        vector<int>freq(26,0);
        for(int j=i;j<n;j++)
        {
            freq[s[j]-'a']++;
            if(isunique(freq)==true) cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    string s = "aabcbcdbca";
    int totalCnt = substringshavingunique(s);
    cout<<totalCnt<<endl;
    return 0;
}


Optimal approach : // so here is the most optimal approach 

#include<bits/stdc++.h>
using namespace std;

int substringshavingunique(string &s)
{
    int n = s.size();
    int cnt = 0;
    unordered_map<char,int>mp;
    int i=0,j=0;
    while(j<n)
    {
        while(i<j && mp.find(s[j]) != mp.end())
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        
        cnt += j-i+1;
        mp[s[j]]++;
        j++;
        
    }
    
    return cnt;
}

int main()
{
    string s = "aabcbcdbca";
    int totalCnt = substringshavingunique(s);
    cout<<totalCnt<<endl;
    return 0;
}
