https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11

Approach 1 :

Use find function 

Approach 2 :

Using stack 

Traverse the string and push the characters into the stack 
If the size of the stack becomes greater than the part size of the string then check from the back of the part string and compare with the top of the stack
if same then pop the top element from the stack

Approach 3 :

Using string temp

Check in the temp itself if available then erase the part string from the temp like this do so and so

Approach 4 :

Using KMP Algorithm

If there is question like check the pattern string that present in original string then immediately we have to remember KMP algo


