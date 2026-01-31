


Approacch - 1 :
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        int i = 0,j=0;
        while(i<n/2 && j<n/2)
        {
           ans.push_back(pos[i]);
           ans.push_back(neg[i]);
           i++;
           j++;
        }

        return ans;
    }
};

This approach is only works in the case of positives == Negatives

Approach 2 :

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

       int n = nums.size();
       vector<int>ans(n,0);
       int posIndex = 0,negIndex = 1;
       for(int i=0;i<n;i++)
       {
          if(nums[i]>0)
          {
             ans[posIndex] = nums[i];
             posIndex += 2;
          }
          else
          {
            ans[negIndex] = nums[i];
            negIndex += 2;
          }
       }   

       return ans;
    }
};

Problem (version -2):

Pos's != Neg's

then may be Pos's > Neg's
  or else Pos's < Neg's

Problem Link : https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
