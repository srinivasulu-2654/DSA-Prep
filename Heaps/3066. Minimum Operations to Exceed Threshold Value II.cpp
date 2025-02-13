https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        while(!pq.empty())
        {
            long long a = pq.top();
            if(a>=k)
            {
                break;
            }
            else
            {
                pq.pop();
            }
            long long b = pq.top();
            pq.pop();
            
            long long temp = a * 2 + b;
            
            pq.push(temp);
            ans++;
        }
        return ans;
    }
};
