https://leetcode.com/problems/move-pieces-to-obtain-a-string/?envType=daily-question&envId=2024-12-05

From this we got to know that all the L's R's and _'s are in equal count
The order for the start and target also should be the same

For example :   "_L__R__R_"    "_L__R__R_"    seee here the order is same so it can be possible 

 start = "R_L_", target = "__LR"  here order is not in uniiform then it can't be possible


class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i=0,j=0;
        while(i<n && j<n)
        {
            while(i<n && start[i] == '_') i++;
            while(j<n && target[j] == '_')j++;

            if(i==n || j==n) break;

            if(start[i] != target[j]) return false;
            if(start[i] == 'R' && i>j) return false;
            if(start[i] == 'L' && i<j) return false;

            i++;
            j++;
        }
       while(i<n && start[i] == '_') i++;
       while(j<n && target[j] == '_') j++;
        return i==n && j==n;
    }
};
