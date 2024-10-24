https://leetcode.com/problems/sliding-window-maximum/description/

Approach is :
first we have to find out the max ele in each and every window of array so that,
while(j<n){
// calculation
if(j-i+1<k) j++;
else if(j-i+1==k){
  // get answer 
   i++;
   j++;
 }
}

// Calculation lo em cheyali ante

   [1,3,-1,-3,5,3,6,7]
for example ippudu temp lo [1,....] store cheskunnam and manam j ni 3 meediki teccham so appudu enti 3 max ainappudu 
dani front unnavi anni waste ane kada dani  meaning so daniki mundhu unnavi anni pop chesthe ok 

// appudu answer temp.front() avuthundi

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        vector<int>temp;
        int n = nums.size();
        int i=0,j=0;
        while(j<n)
        {
            while(temp.size()>0 && temp.back()<nums[j])
            {
                temp.pop_back();
            }
            temp.push_back(nums[j]);

            if(j-i+1<k) j++;
            else if(j-i+1==k)
            {
                ans.push_back(temp.front());
                if(temp.front()==nums[i]) temp.erase(temp.begin());
                i++;
                j++;
            }
        }

        return ans;
    }
};

Time Complexity: O(n * k) (due to costly erase operation in temp)
Space Complexity: O(n + k)
