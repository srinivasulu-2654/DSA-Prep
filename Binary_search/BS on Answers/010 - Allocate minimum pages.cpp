https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

/*
  -> same like min(max) or max(min)
  -> arr[] = {25 46 28 49 24} students = 4
  -> so this problem is related to maximize the minimum
  -> s1 = 25 s2 = 46 s3 = 28 s4 = 49 and 24 => maximum=73
  -> s1 = 25 s2 = 46 s3 = 28 49 s4 = 24 => max = 77
  -> so like this we have return minimum out of maximum

  -> so here instead of taking pages from 1 onwards will take from mini like from 24
  -> even if he want to hold a book mini he required 24 pages
  -> if we start from 24 also no one will hold 25 46 28 49
  -> instead of starting from 24 will start from maximum of the given pages
  -> mini = max(array) 
  -> if students = 1 then we can allocate to that student whole array right so take maximum of the array
*/
