https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10


class Solution {
public:

   int mod = 1e9+7;
   
    int countPermutations(vector<int>& complexity) {
        
        /* so here if we have [3,2,3,4]  then it wont even set coz 0<1 this is okay but 
        complexity[0] < complexity[1] this is false so cant make unlock the computers
        and in normal case [1,2,3,4] here in first place only 1 possiblity coz that is the root 
        of the unlocking and remaining places and it will come like this 
        1*3*2*1 -> 1 * n-1 * n-2* n-3 * ..... 1 */

        int n = complexity.size();
        long long res = 1;
        for(int i=1;i<n;i++)
        {
           if(complexity[i]<=complexity[0]) return 0;
           else res = (res * i) % mod;
        }

        return res;

    }
};
