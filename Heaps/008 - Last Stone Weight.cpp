https://leetcode.com/problems/last-stone-weight/description/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>maxi;
        
        for(int i=0;i<n;i++)
        {
            maxi.push(stones[i]);
        }

        while(maxi.size()>1)
        {
            
                int firstEle = maxi.top();
                maxi.pop();
                int secondEle = maxi.top();
                maxi.pop();
                int val = abs(firstEle-secondEle);
                if(val!=0) maxi.push(val);
            
        }

        return maxi.size() == 0 ? 0 : maxi.top();
    }
};
