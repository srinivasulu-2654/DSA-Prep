/*
  Approach 1:
  -> here take arr[i] = x and search for x+1 then increase cnt and track maximum cnt;
*/

class Solution {
public:

    bool linearSearch(vector<int>&nums,int x)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == x) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            int cnt = 1;
            while(linearSearch(nums,x+1) == true)
            {
                x = x+1;
                cnt++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

Approach 2 :

/*
  -> sort and track the lastSmaller = INT_MIN
  -> but it will take O(n) + O(nlogn)
  -> but we want this in only O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0,lastEle=INT_MIN;
        int longest = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] - 1 == lastEle)
            {
                cnt++;
                lastEle = nums[i];
            }
            else if(nums[i] != lastEle)
            {
                cnt = 1;
                lastEle = nums[i];
            }

            longest = max(longest,cnt);
        }
        return longest;
    }
};

Approach 3:

/*
-> we have to declare the unordered set
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int cnt = 0;
        int longest = 0;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        for(auto it:st)
        {
            if(st.find(it-1) == st.end())
            {
                cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x =x+1;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
