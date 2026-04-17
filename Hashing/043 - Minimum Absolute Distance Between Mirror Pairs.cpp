class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>mp;
        int res = INT_MAX;
        for(int i=0;i<n;i++)
        {

            if(mp.find(nums[i]) != mp.end())
            {
                res = min(res,abs(i-mp[nums[i]]));
                mp[nums[i]] = i;
            }

            int num = nums[i];
            string temp = to_string(num);
            reverse(temp.begin(),temp.end());
            int j = 0;
            while(j<temp.size())
            {
                if(temp[j]=='0') j++;
                else break;
            }

           temp =  temp.substr(j,temp.size()-j);
            num = stoi(temp);
            mp[num] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};
