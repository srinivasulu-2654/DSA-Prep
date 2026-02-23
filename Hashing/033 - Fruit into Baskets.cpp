// https://leetcode.com/problems/fruit-into-baskets/
// so this problem just gave theory more but compare this problem is same as:
// longest continuous subarray that contains at most 2 distinct numbers.

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
