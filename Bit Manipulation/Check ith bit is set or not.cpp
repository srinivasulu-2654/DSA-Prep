/*
  check i th bit is set or not

  n = 13 , i = 2

  1. Bruete force approach like change the decimal into binary and check for that in a stored string

  2. so using bit manipulation na 
     i) first do (1 << i) => (1 << 2)
     ii) do n && (1 << i) 
     iii) if the result is 1 then true
     iv) else false

  3. by doing right shift also we can do
     i) n >> k
     ii) & with 1

  TC : O(1) SC : O(1)
  
*/
