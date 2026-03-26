https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

Do this question

/* 
  -> same above question only but we have to do gcd for the nums[i] with k
  -> here the greatest commen divisior will be the common factor to multiply both and divisble by k
  -> Here check g1 and g2 properly
*/

class Solution {
public:

    int findgcd(int a,int b)
    {
        if(b==0) return a;
        return findgcd(b,a%b);
    }

    long long countPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int>mp;
        long long cnt = 0;
        for(int num:nums)
        {
            int g1 = findgcd(num,k);
            for(auto it:mp)
            {
                int g2 = it.first;
                int freq = it.second;
                if((1LL*g1*g2) % k == 0){
                    cnt += freq;
                }
            }
            mp[g1]++;
        }

        return cnt;
    }
};
