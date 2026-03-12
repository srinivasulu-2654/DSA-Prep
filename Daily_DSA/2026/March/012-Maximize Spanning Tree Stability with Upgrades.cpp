/*
Steps to resolve:
                    s
-> [u,v,s,m]    u ------ v  => here u,v are nodes and s is strength and also m = 0 or m = 1 i mean edge should compulosry present m = 0 may or may not be
-> m = 1 should be included in spanning tree and can not upgrade
-> m = 0 can be upgraded
-> upgrade = (2*s)
-> stability => minimum of all strenghts of edges
-> return Maximum of the minimum stability

-> MAX(stability)

-> maximize the miniumum means blindly use Binary search

-> Binary Search on Answer

-> here statbility will be from low = 1 and high = 2 * 10^5 becuase we are doing the 2 * stability right


->    2 --------- 3
      |
      |
      |
      1

      -> here wheather 1 and 3 connected or not should check in DSU(disjoint set union)
      -> I mean spanning tree means 3 -> 2 -> 1 so somehow connected right this is called spanning tree 
      -> if we use DSU na find(1) = 2
                          find(3) = 2
                          
      -> here we are checking for upgraded components when should upgrade na m = 0 and also if it wont connect na then we can upgrade
      -> here in this case 2->3->1 already connected then no need to waste by connecting 1 -> 3

*/

