https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        
        int n = arr.size();
        unordered_map<int,int>mp;
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int anotherEle = target - arr[i];
            
            if(mp.find(anotherEle) != mp.end())
            {
                cnt += mp[anotherEle];

            }
            
             mp[arr[i]]++;
        }
        
        return cnt;
    }
};
