https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


   class Solution {
  public:
    int longestKSubstr(string &str, int k) {
        // code here
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

       if(mp.size()==k) maxi = max(maxi,j-i+1);
        j++;
    }

    return maxi != 0 ? maxi : -1;
    }
};
