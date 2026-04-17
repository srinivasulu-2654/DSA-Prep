/* 
    https://leetcode.com/problems/longest-valid-parentheses/description/
    -> this can be solved in various types 
    -> I guess stack will take more complex 

    so here this present code also first part for loop will work only in this case -> s = ())(())
    but in this case it will fail -> s = (() -> thus we have handled the 2nd part of the for loop

    -> very tricky question have tried to solve using stack but not possible
*/

class Solution {
    public int longestValidParentheses(String s) {
        
        int n = s.length();
        int res = 0;
        int open = 0;
        int close = 0;
        for(int i=0;i<n;i++)
        {
            if(s.charAt(i)=='(') open++;
            else close++;
            if(open == close)
            {
                res = Math.max(res,open*2);
            }
            else if(open<close)
            {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(s.charAt(i)=='(') open++;
            else close++;
            if(open == close)
            {
                res = Math.max(res,open*2);
            }
            else if(open>close)
            {
                open = 0;
                close = 0;
            }
        }

        return res;
    }
}

