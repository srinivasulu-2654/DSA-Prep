https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02


class Solution {
public:
   
   bool isVowel(char &ch)
   {
       if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
       {
          return true;
       }

       return false;
   }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        int q = queries.size();
        vector<int>currSum(n);
        vector<int>res(q);

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
            {
                sum++;
            }

            currSum[i] = sum;
        }

        for(int i=0;i<q;i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            res[i] = currSum[r] -  ((l>0) ? currSum[l-1] : 0);
        }

        return res;
    }
};
