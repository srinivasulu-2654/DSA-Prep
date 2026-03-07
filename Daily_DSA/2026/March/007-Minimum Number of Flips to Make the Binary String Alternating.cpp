-> https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/?envType=daily-question&envId=2026-03-07

    /*
        Approach 1:
        
        -> we already solved this type of question in (leetcode 1758)
        -> but there wasn't type 1
        -> now we have to use as many times as Type - 1
        -> now for example: s = 111000
        -> for 1st append s = 110001
        -> for 2nd append s = 100011
        -> for 3rd append s = 000111
        -> for 4th append s = 001110
        -> for 5th append s = 011100
        -> for 6th append s = 111000
        -> see finally it came to it's original position now stop
        -> every time we have to generate appened string and pass to our main function take
           min(start_0, start_1)
    */

   /*
       Approach 2: Sliding Window
       s = s + s
       now s = 111000111000
       so here if we slide the window of size n then all the above forms can see instead of generating string every time we can do this
    */

class Solution {
public:
    int minFlips(string s) {
       
        int n = s.length();
        s = s + s;

        string s1,s2;

        for(int i=0;i<2*n;i++)
        {
            s1 += (i%2 == 0) ? '0' : '1'; // even places '0' and odd places '1'
            s2 += (i%2 == 0) ? '1' : '0'; // even places '1' and odd places '0'
        }

        int res = INT_MAX;
        int flip1 = 0,flip2 = 0;

        int i = 0,j=0;

        while(j<2*n)
        {
            if(s[j] != s1[j]) flip1++;
            if(s[j] != s2[j]) flip2++;

            if(j-i+1 > n)
            {
                if(s[i] != s1[i]) flip1--;
                if(s[i] != s2[i]) flip2--;

                i++;
            }

            if(j-i+1 == n)
            {
                res = min({res,flip1,flip2});
            }

            j++;
        }

        return res;
    }
};

-> So here same approach in java is getting error becuase of Strings immutable
-> in java strings are immutable I mean everything new object will creat
-> instead that we can able to use StringBuilder 
Every time Java:

1️⃣ Creates new object
2️⃣ Copies old string
3️⃣ Adds new character

🔟 Quick Real-Life Analogy

Think like this:

String (Immutable)
Notebook written with pen
If you want to change → write new page
StringBuilder (Mutable)
Whiteboard
You can erase and rewrite on the same board

Approach - 3:

So no need to take this s = s + s 
-> in normal string only j will become out of the bound so immediately we have to do j % n and i % n

  Approach 4 :

  class Solution {
public:
    int minFlips(string s) {
       
        int n = s.length();

        int res = INT_MAX;
        int flip1 = 0,flip2 = 0;

        int i = 0,j=0;

        while(j<2*n)
        {
            char ch1 = (j % 2 == 0) ? '0' : '1';
            char ch2 = (j%2 == 0) ? '1' : '0';

            if(s[j%n] != ch1) flip1++;
            if(s[j%n] != ch2) flip2++;

            if(j-i+1 > n)
            {
                char ch1 = (i% 2 == 0) ? '0' : '1';
                char ch2 = (i%2 == 0) ? '1' : '0';

                if(s[i%n] != ch1) flip1--;
                if(s[i%n] != ch2) flip2--;

                i++;
            }

            if(j-i+1 == n)
            {
                res = min({res,flip1,flip2});
            }

            j++;
        }

        return res;
    }
};
