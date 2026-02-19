https://www.geeksforgeeks.org/problems/max-consecutive-one/1

class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int maxi = 0;
        int zerocnt = 0;
        int onescnt = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                zerocnt++;
                maxi = max(maxi,zerocnt);
                onescnt = 0;
            }
            else if(arr[i]==1)
            {
                onescnt++;
                maxi = max(maxi,onescnt);
                zerocnt=0;
            }
            
        }
        
        return maxi;
    }
};
