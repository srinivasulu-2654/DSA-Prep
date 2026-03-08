Approach 1 :

-> Even we can able to do with recursion or backtracking also
-> generate all the strings of n length then check wheather if the generated string is present or not
-> then return the result

Approach 2:
-> Here in each i th character if we do change 1 character also it will become completely new string 
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        string res = "";
        for(int i=0;i<n;i++)
        {
            char ch = nums[i][i]; 
            if(ch == '1') res += '0';
            else res += '1';
        }

        return res;
    }
};
