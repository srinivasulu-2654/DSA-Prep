Approach 1 :

/*
  instead of taking sub string everytime you can take vector<string>res 
  push back everytime and finally reverse that's it
  examples : a good   example ( there are 3 spaces)
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j;
        string res = "";
        while(i<n)
        {
            while(i<n && s[i] == ' ') i++;
            if(i>=n) break;
            j = i+1;
            while(j<n && s[j] != ' ')j++;
            string sub = s.substr(i,j-i);
            if(res.empty()) res = sub;
            else res = sub + " " + res;
            i = j+1;

        }

        return res;
    }
};

Approach 2:

/* 
  -> this is simply we are doing inplace so that it will get reverse of words
  -> take i=0,l=0,r=0;
  -> if space visible just increase i++;
  -> if not space s[r] = s[i] and then increase r++,i++;
  -> in certain point i will stop if it sees space
  -> then check (l<r) and then reverse those with l and r
  -> and word after make s[r] = ' '
  -> do r++, and l = r
  -> at last make like this substr(0,r-1) becuase at times space will be there right
  
*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int i = 0,l=0,r=0;
        while(i<n)
        {
            // if until we wont see space 
            while(i<n && s[i] != ' ')
            {
                s[r] = s[i];
                i++;
                r++;
            }
            // if we see space just do this
            if(l<r)
            {
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }

       s =  s.substr(0,r-1); // if this make space at last
        return s;
    }
};
