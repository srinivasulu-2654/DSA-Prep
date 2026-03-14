https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14
/*

-> Here  we have to generate the strings in the sense blindly we can use back tracking 
-> n = 3, k = 9 i mean a,b,c using this we have to generate the string and also str[i] != str[i+1]
-> also return k = 9 th string

TC :
---  ---  --- I mean here in 1st place we can select 3 posibilites
              in 2nd place only 2
              in 3rd place only 2

              so 3 * 2 * 2 * 2 * 2 * 2 ............
              => 3 * 2 ^ n-1 => 2^n possibilites
we are storing in result string => O(n * 2 ^ n)
SC = O(2 ^ n * n) these many string are storing 

*/

Approach 1: (Here we are generating all the possible string so no need the extra space will cover in aprraoch 2)

class Solution {
public:

    void solve(string &curr,vector<string>&res,int n)
    {
        if(curr.length()==n)
        {
            res.push_back(curr);
            return;
        }

        for(char ch = 'a';ch<='c';ch++)
        {
            if(!curr.empty() && curr.back() == ch) continue;

            // do
            curr.push_back(ch); 

            // explore 
            solve(curr,res,n);

            // undo
            curr.pop_back();
        }

        return;
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string>res;
        solve(curr,res,n);
        if(res.size() < k) return "";
        return res[k-1];
    }
};

Approach 2:
class Solution {
public:

    void solve(string &curr,string &res,int n,int &cnt,int k)
    {
        if(curr.length()==n)
        {
           cnt++;
           if(cnt == k)
           {
                res = curr;
           }
           return;
        }

        for(char ch = 'a';ch<='c';ch++)
        {
            if(!curr.empty() && curr.back() == ch) continue;

            // do
            curr.push_back(ch); 

            // explore 
            solve(curr,res,n,cnt,k);

            // undo
            curr.pop_back();
        }

        return;
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int cnt = 0;
        solve(curr,res,n,cnt,k);
        return res;
    }
};

SC : O(n) -> here we have reduced the spaace complexity of 2 ^ n
