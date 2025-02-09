https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

/* Approach 1:

1. // For this probelm direct bruete force approach is O(n^2)
2. If the problem will give about the index and numbers then we have to do like this

 Approach 2 : 
  j - i != nums[j] - nums[i] -> we can write this as nums[i] - i != nums[j] - j

  then the seperate array will create like this j - i != nums[j] - nums[i] */

Approach 2 : 

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i] - i;
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i<j && nums[i] != nums[j]) cnt++;
            }
        }

        return cnt;
    }
};

TC : O(n^2)

Approach 3 :

// use map and for the particular index check for the left  elements which are not equal to the current element in the array

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i] - i;
        }

        unordered_map<int,int>mp;

        mp[nums[0]] = 1;

        for(int j = 1;j<n;j++)
        {
            int countofNumsj = mp[nums[j]];
            int totalnumsj = j;

            int badPairs = totalnumsj - countofNumsj;

            cnt += badPairs;

            mp[nums[j]]++;
        }

        return cnt;
    }
};

Appraoch : 4

  class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i] - i;
        }

        unordered_map<int,int>mp;

        mp[nums[0]] = 1;

        for(int j = 1;j<n;j++)
        {
            int totalPairs = j;
            int goodPairs = mp[nums[j]];
            int badPairs = totalPairs - goodPairs;

            cnt += badPairs;

            mp[nums[j]]++;
        }

        return cnt;
    }
};

