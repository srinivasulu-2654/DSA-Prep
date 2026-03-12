/*
   so here [1 2 3 4 5 6 7 8 9 10] days = 5 
   so if we take capactiy = 100
    then all the weights can ship within 1 day but we want minimum weight to ship in d days
    so for that if we take capacity  = 10 then it will take i think 7 days but we want in d days
    so take capactity = 15 like that low = maxi , high = sum of all weights

  
*/
class Solution {
public:

    bool daysRequired(vector<int>& weights, int capacity,int days)
    {
        int daysTaken = 1; // coz last element wont count if it crosses
        int sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            if(sum + weights[i] > capacity)
            {
                daysTaken++;
                sum = weights[i];
            }
            else {
                sum += weights[i];
            }
        }

        return daysTaken <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int ans = -1;
        int n = weights.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++) maxi = max(maxi,weights[i]);
        int sum = 0;
        for(int i=0;i<n;i++) sum += weights[i];
        int low = maxi,high = sum;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(daysRequired(weights,mid,days) == true)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};
