class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int xorr = 0;
        for(int i=0;i<nums.size();i++)
        {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};


a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
(1 ^ 1) ^ (2 ^ 2) ^ 4

    Order is not a problem here 
