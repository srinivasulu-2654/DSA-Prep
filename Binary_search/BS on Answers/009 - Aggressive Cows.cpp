https://www.geeksforgeeks.org/problems/aggressive-cows/1

/*
    -> so from now we will do next 4 to 5 problem in min(max) or max(min)
    -> coming to this question [ 0 3 4 7 10 9] k = 4
    -> given normal array we have to sort that array(because we want min distance of all possibilites in that we want to return maximum)
    -> for that [0 3 4 7 9 10]
    -> if we put like this c1 c2 c3 c4 => min is 1
    -> c1 in 0 c2 in 4 c3 in 9 c4 in 10 => min distance is 1
    -> if is like c1 0 c2 4 c3 7 c4 10 -> min dist is 3
    => among all we have to return maximum

    Steps : 
    -> sort the array there by will get minimum distance 
    -> take like maintain distance of 1,2,3,4.... between the stalls
    -> at minimum you always should have 2 cows
    -> so then minimum = 1 distance and maximum distance = (max - min)
    -> 
*/

Approach 1 (Linear Approach) :

class Solution {
  public:
  
    bool canWePlaceCows(vector<int> &stalls, int k,int dist)
    {
        int cntcows = 1;
        int lastPlaced = stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i] - lastPlaced >= dist)
            {
                cntcows++;
                lastPlaced = stalls[i];
            }
        }
        
        return cntcows >= k;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        int ans = -1;
        
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int mini = stalls[0];
        int maxi = *max_element(stalls.begin(),stalls.end());
        for(int i=1;i<=maxi-mini;i++)
        {
            if(canWePlaceCows(stalls,k,i) == true) 
            {
                ans = i;
            }
            else break;
        }
        
        return ans;
    }
};

Binary Search Appraoch (min max method):

class Solution {
  public:
  
    bool canWePlaceCows(vector<int> &stalls, int k,int dist)
    {
        int cntcows = 1;
        int lastPlaced = stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i] - lastPlaced >= dist)
            {
                cntcows++;
                lastPlaced = stalls[i];
            }
        }
        
        return cntcows >= k;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        int ans = -1;
        
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int mini = stalls[0];
        int maxi = *max_element(stalls.begin(),stalls.end());
        
        int low = 1,high = maxi-mini;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(canWePlaceCows(stalls,k,mid) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return ans;
    }
};
