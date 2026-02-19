https://leetcode.com/problems/rabbits-in-forest/description/

Refer Day - 09 1:07:45

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int n = answers.size();
        int total = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[answers[i]]++; // grouping the rabbits (frequencey) of same color

        for(auto it:mp)
        {
            int x = it.first;
            int count = it.second;

            int groupSize = x + 1;
            int groups = ceil((double)count/groupSize); // to know how many groups needed for same color [2,2,2,2] if it is like this - - - then for another 2 we have to create seperate group

            total += groupSize * groups;
        }

        return total;
    }
};
