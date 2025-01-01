https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

Bruete Force : 

class Solution {
public:
    int maxScore(string s) {
        
        int ans  = 0;

         int n = s.size();

         for(int i=0;i<n-1;i++)
         {
            int curr = 0;

            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0'){
                    curr++;
                }
            }

            for(int k = i+1;k<n;k++)
            {
                if(s[k]=='1'){
                    curr++;
                }
            }

            ans = max(ans,curr);
         }

         return ans;
    }
};


Optimal approach :

class Solution {
public:
    int maxScore(string s) {
       int ans = 0;
       int zeros =0,ones =0;

       for(int i=0;i<s.size();i++) if(s[i]=='1') ones++;

       for(int i=0;i<s.size()-1;i++)
       {
          if(s[i]=='0') zeros++;
          else if(s[i]=='1') ones--;

          ans = max(ans,zeros + ones);
       }

       return ans;
    }

};
