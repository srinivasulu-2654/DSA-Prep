https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    
    int windowsizemini(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size();
        int mini = INT_MAX;
        int i=0,j=0;
        int currSum = 0;
        while(j<n)
        {
            currSum += cardPoints[j];
            if(j-i+1<k) j++;
            else if(j-i+1==k)
            {
                mini = min(mini,currSum);
                currSum -= cardPoints[i];
                i++;
                j++;
            }
        }
        

        return mini;
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for(int i=0;i<n;i++) totalSum += cardPoints[i];
        if(n==k) return totalSum;
        int windowSize = n - k;
        int windowVal = windowsizemini(cardPoints,windowSize);
        return totalSum - windowVal;

    }
};
