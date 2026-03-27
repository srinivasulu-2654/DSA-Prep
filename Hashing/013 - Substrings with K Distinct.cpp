https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

We have to   do this question also 

/*
  -> Here it is coming TLE if we are using that hashmap things and all instead we can use the freq array
  -> we can able to track the distinct keyword and then will track
*/

  class Solution {
  public:
  
    int substrings_having_atmost_k_unique_characters(string &s,int k)
{
    int n = s.size();
    int cnt = 0;
   vector<char>freq(26,0);
   int distinct = 0;
    int i=0,j=0;
    while(j<n)
    {
        if(freq[s[j] - 'a'] == 0) distinct++;
        freq[s[j] - 'a']++;
        
        while(distinct>k)
        {
            freq[s[i]-'a']--;
            if(freq[s[i] - 'a'] == 0) distinct--;
            i++;
        }
        
        cnt += j-i+1;
        j++;
    }
    
    return cnt;
}
  
    int countSubstr(string& s, int k) {
        // code here
        int res = substrings_having_atmost_k_unique_characters(s,k) - substrings_having_atmost_k_unique_characters(s,k-1);
        return res;
    }
};
