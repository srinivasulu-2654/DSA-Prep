// there is no link for this but have reference for this problem

https://algo.monster/liteproblems/487

#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveonesii(int nums[],int n)
{
    int zerocnt = 0;
    int i=0;
    int maxi = 0;
    
    // so here aim is we have to  flip only atmost 1 zero so if zerocnt > 1 then need to reduce the window
    
    for(int j=0;j<n;j++)
    {
        if(nums[j]==0) zerocnt++;
        
        while(zerocnt>1)
        {
            if(nums[i]==0)
            {
                zerocnt--;
            }
            
            i++;
        }
        
        maxi = max(maxi,j-i+1);
    }
    
    return maxi;
 }


int main()
{
    int nums[] = {1,1,0,1,0,1,1,1,0,1,1,1,1,0,1};
    int val = maxConsecutiveonesii(nums,15);
    cout<<val<<endl;
    return 0;
}
