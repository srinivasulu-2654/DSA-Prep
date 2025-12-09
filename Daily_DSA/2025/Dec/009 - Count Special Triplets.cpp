class Solution {
public:

    int mod = 1e9+7;
    
    int specialTriplets(vector<int>& nums) {
        
        unordered_map<int,int>leftmp;
        unordered_map<int,int>rightmp;

        for(int num:nums) rightmp[num]++;
        
        int res = 0;

        for(int num:nums)
        {
            rightmp[num]--;
            int mul = 2 * num;
            int left = leftmp[mul];
            int right = rightmp[mul];
            
            res = (res + (1LL * left * right)) % mod;
            leftmp[num]++;
        }

        return res;
    }
};
