https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10

Approach 1:

class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;
        int n = s.size();
        for(char ch:s)
        {
            if(isalpha(ch))
            {
                st.push(ch);
            }
            else if(isdigit(ch))
            {
                if(!st.empty()) st.pop();
            }
        }

        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};

TC : O(n)
SC : O(n)

Approach 2:

class Solution {
public:
    string clearDigits(string s) {
        // int n = s.length() // if we write this it will give wrong because the lenght of the string continuously changing it's length

        int i = 0;
        while(i<s.length())
        {
            if(isdigit(s[i]))
            {
                s.erase(i,1);
                if(i-1>=0)
                {
                    s.erase(i-1,1);
                    i--;
                }
            }
            else i++;
        }

        return s;
    }
};

TC : O(n^2)

Approaach 3 :

class Solution {
public:
    string clearDigits(string s) {
        
        int n = s.size();
        string res = "";
        for(char &ch:s)
        {
            if(isdigit(ch))
            {

                if(!res.empty()) res.pop_back();
            }
            else res.push_back(ch);
        }
        return res;
    }
};

Tc:O(n)
SC:O(n)

Approach 4 :

class Solution {
public:
    string clearDigits(string s) {
        
        int n = s.size();
        int i=0,j=0;
        while(i<n)
        {
            if(isdigit(s[i]))
            {
                j = max(j-1,0); // to prevent j from negative
                //j--; // in future if ith index finds a valid character we will put that at index j   
            }
            else {
                s[j] = s[i];
                j++;
            }
            i++;
        }

        return s.substr(0,j);
    }
};
