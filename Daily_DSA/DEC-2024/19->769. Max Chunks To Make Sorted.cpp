https://leetcode.com/problems/max-chunks-to-make-sorted/?envType=daily-question&envId=2024-12-19

same like anagram problem

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = 0;
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i]);

            if(maxi==i) cnt++;
        }
        return cnt;
    }
};
