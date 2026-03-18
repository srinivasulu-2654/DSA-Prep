https://leetcode.com/problems/median-of-two-sorted-arrays/description/

/* 
  -> Bruete force will be we have to add into 3rd array or temp array
  -> then n % 2 == 1 then straight away return temp[n/2]
  -> or else return temp[n/2] + temp[n/2-1] / 2.0
  -> like mid + (mid-1) / 2 in case of even length 
  -> mid/2 in case of odd length
*/

/* 
  Optimal Approach:
  -> so here we have to track with cnt and also int n = n1 + n2;
  -> put ele1 = -1,ele2 = -1, ind2 = n/2 and ind1 = ind2-1;
  ->
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
         int i = 0,j=0;

        int n = n1+n2;
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int cnt = 0;

        int ele1 = -1,ele2 = -1;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                if(cnt == ind1) ele1 = nums1[i];
                if(cnt == ind2) ele2 = nums1[i];
                cnt++;
                i++;
            }
            else
            {
               if(cnt == ind1) ele1 = nums2[j];
               if(cnt == ind2) ele2 = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
            if(cnt == ind1) ele1 = nums1[i];
                if(cnt == ind2) ele2 = nums1[i];
                cnt++;
                i++;
        }
         while(j<n2){
            if(cnt == ind1) ele1 = nums2[j];
               if(cnt == ind2) ele2 = nums2[j];
                cnt++;
                j++;
        }

        if(n%2 == 1) return ele2;

        return (double)(ele1+ele2)/2.0;
    }
};
