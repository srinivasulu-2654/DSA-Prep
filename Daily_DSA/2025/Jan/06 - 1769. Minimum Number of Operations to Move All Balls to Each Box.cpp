https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06


class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();

        vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            int indx = 0;

            if(boxes[i]=='1')
            {
                indx = i;
            

            for(int j=0;j<n;j++)
            {
                ans[j] += abs(indx - j);
            }

            }
        }

        return ans;
    }
};
