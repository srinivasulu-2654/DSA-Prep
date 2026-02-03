// 2. Better Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            set<int>hashSet; // everytime for ith ele we have reset the set

            for(int j=i+1;j<n;j++)
            {
                int  third = -(nums[i]+nums[j]);
                if(hashSet.find(third) != hashSet.end())
                {
                    vector<int>temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

TC : O(n^2) * log m
// SC : O(n) + O(external data structure)


Appraoch 3 - (Optimal approach)

  
class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i]==arr[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            
            while(j<k)
            {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else
                {
                    vector<int>temp = {arr[i],arr[j],arr[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    
                    while(j<k && arr[j]==arr[j-1])j++;
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
            }
        }
        
        return res;
    }
};
