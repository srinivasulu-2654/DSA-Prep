https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=daily-question&envId=2026-04-19

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxi = 0;
        int i=0,j=0;
        while(i<n1 && j<n2)
        {

            if(nums1[i]>nums2[j])
            {
                i++;
            }
            else
            {
                maxi = max(maxi,j-i);
                j++;
            }
        }

        return maxi;
    }
};
