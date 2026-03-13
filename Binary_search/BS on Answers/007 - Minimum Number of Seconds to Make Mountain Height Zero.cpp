Minimum Number of Seconds to Make Mountain Height Zero
/*

-> so here the problem is to reduce the mountain height thus 
-> we have to return minimize the maximum
-> for example in this:
  Input: mountainHeight = 4, workerTimes = [2,1,1]

  t0 -> w0
  t1 -> w1   => max(w0,w1,w2) => ans1
  t2 -> w2

  t0* -> w0*
  t1* -> w1*   => max(w0*,w1*,w2*) => ans2
  t2* -> w2*

  ans => min(ans1,ans2)

  -> so here minimize the maximum

here the formula will be like this t*(h*(h+1)/2) <= mid

-> simplify this now h <= sqrt(2*mid/t+0.25-0.5

*/

class Solution {
public:

    typedef long long ll;

    bool check(ll mid,int mountainHeight,vector<int>& workerTimes)
    {
        ll h = 0;
        for(int t : workerTimes)
        {
            h += (ll)(sqrt(2.0*mid/t + 0.25) - 0.5);

            if(h >=mountainHeight) return true;
        }

        return h >= mountainHeight;

    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        int maxTime = *max_element(begin(workerTimes),end(workerTimes));
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight+1)/2;

        ll result = 0;

        while(l<=r)
        {
            ll mid = (l+r)/2;
            if(check(mid,mountainHeight,workerTimes) == true) {
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;   
        }

        return result;
    }
};
