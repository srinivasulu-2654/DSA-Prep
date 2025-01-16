/* What are set bits?
  
The number of 1s that are present in the binary representation of a number.
For example:
11010 has 3 set bits.

How to set a bit position?

  
To set a specific bit position, for example:
If 01010010 needs to have the 0th bit set, it becomes 01010011.

This can be achieved using the expression:

x = x | (1 << i)

  Here, we left-shift 1 to the i-th position and perform the OR (|) operation with x.

How to unset a bit position?

  
To unset a specific bit position, use the expression:

x = x & ~(1 << i)

  Here:

1 << i creates a binary number with a 1 at the  i-th bit.
The NOT (~) operator inverts it.
The AND (&) operation clears the i-th bit.
Example:
If x = 01010011 and you want to unset the 0th bit, the result will be 01010010. */

