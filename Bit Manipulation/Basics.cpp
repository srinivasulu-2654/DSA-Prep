/*

 -> so here if we want to write (13) base 10 in binary form how can we like  will do LCM 
 -> like whatever the remainder that means 13 it will divied with 2 * 6 then remainder will come as 1 so this is binary form and also should write from bottom to top
 -> (1 1 0 1) base 2 convert into decimal na should do from last to first

 Q) Explore the question of convert decimal to binary? TC : O(log2n) because it is dividing half half eveytime, SC : Same becuase we are storing in string
 Q) Explore the question of convert binary to decimal?


 -> SO here 1 important thing like computer only stores 0's and 1's
 -> so if we want to print print(x) that means the binary converts into decimal then it shows in display as decimal form
 -> int x = 13 so  1 1 0 1 this is 4 bits but actual memory is 32 so remaining all will store 0's

 -> 1's compliment na for example (13) -> (1 1 0 1) -> flip that's it -> ( 0 0 1 0)
 -> 2's compliment na 
    i) 1's compliment
    ii) add 1 to it

 -> AND operator all true -> true
    1 false then false

 -> OR opertor

 -> XoR -> 
    i) if odd number of 1's then 1
    ii) if even number of 1's then 0

  -> Right shift operator(>>) 13 >> 1 then 1 bit move to right that means it will disappera
     13 >> 2 now 2 bits

   -> Heere technically formula is  x >> k = (x/2^k) that means k is any number like 1 , 2, 3,4 

  -> Important topic:
   computer stores 32 bit like x = + 13 what if it is negative x = -13
   -> for negative 31st bit is store for sign that means + or - 
   -> in that sign bit(31st bit) 0 for +ve and 1 for -ve
   -> so here for example x = -13 then how you will write na -> 2's compliment like that write
      i) 1's compliment
      ii) add it to 1

    -> largest number that will store na 2^31 - 1 -> INT_MAX
    -> minmum value na -2^31 -> INT_MIN


 -> left shift operator(<<)

 here in end it will add the 0 to num

 (num << k = num * 2 ^k)

 -> NOT operator(~) x = ~(5)
    i) flip
    ii) check for -ve
        if yes do 2's compliment
        if not stop
 
    

*/
