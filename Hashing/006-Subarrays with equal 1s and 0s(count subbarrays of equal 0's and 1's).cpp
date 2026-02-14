class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int cnt = 0;
        int prefixSum = 0;
        unordered_map<int,int>mp;
        mp[prefixSum] = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) prefixSum+=-1;
            else prefixSum+=1;
            
            if(mp.find(prefixSum) != mp.end())
            {
                cnt += mp[prefixSum];
                mp[prefixSum]++;
            }
            else mp[prefixSum] = 1;
        }
        
        return cnt;
    }
};
