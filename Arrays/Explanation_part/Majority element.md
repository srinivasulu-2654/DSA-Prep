N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4} 

we have to find the element which the count will be greater than the (n/2) 

Bruete Force :

Run 2 loops -> O(n^2)

Approach 1 :

Use map to count the occurences of the element

TC: O(n^2)
SC :O(n)

Approach 2 :
cnt = 0
int ele;

1. First check if the cnt=0 then ele = nums[i]
2. if nums[i] == ele cnt++ or else cnt--
3. again declare cnt1 = 0; and traverse cnt1>n/2 return ele
