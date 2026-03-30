// https://leetcode.com/problems/fruit-into-baskets/
// so this problem just gave theory more but compare this problem is same as:
// longest continuous subarray that contains at most 2 distinct numbers.
// so here the thing is we have to collect of the same type in 2 baskets:
// for example fruits = [0, 1, 2, 2] 0 type , 1 type 2 type but we have only 2 baskets
// if we start from 0 we can collect only 0 and 1 not 2 type
// if we start from 1 index we can collect all 1's and 2's
// so this the longest contigous subarry with contains atmost 2

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        unordered_map<int,int>mp;
        int maxi = 0;
        int i=0,j=0;
        while(j<n)
        {
            mp[fruits[j]]++;
            while(mp.size()>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};
