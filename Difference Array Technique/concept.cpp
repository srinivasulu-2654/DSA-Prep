// Difference Array :

//    Famous technique use to effieciently apply ranges updates to an array. It helps to do multiple updates in constant time.

/* Example :

they will like this :
  n = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]   -- these are the ranges
    Output: [-2,0,3,5,3]  */

// Step 1 : Apply updates using the difference array

// we have to intitlaize diff array oof length n 
vector<int>diff(n,0)

traverse updates vector

for(auto query : updates) {

int left = query[0];
int right = query[1];
int x = query[2];

diff[left] += x;
if(right + 1 < n) diff[right + 1] -= x;

}

// Step 2 :  Compute the final array from the difference array

vector<int>res(n,0);

int currSum = 0;

for(int i=0;i<n;i++){
currSum += diff[i];
res[i] = currSum;
}

return res;


