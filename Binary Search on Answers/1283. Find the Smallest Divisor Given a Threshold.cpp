//  Same as like the question of koko eating bananas

class Solution {
public:
    
    long long check(vector<int>&nums,int threshold,int num)
    {
        int n = nums.size();
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            res += ceil((double)nums[i]/num);
        }

        return res;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();

        int  maxi = INT_MIN;
        for(int i=0;i<n;i++) maxi = max(maxi,nums[i]);

        int l = 1,r=maxi;
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = check(nums,threshold,mid);
            if(val<=threshold)
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};
