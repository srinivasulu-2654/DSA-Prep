/*
  -> Here the idea is we have to swap the source array and should equal to target if not we can return the difference count
  -> source = {1,2,3,4}, target = {2,2,4,5} allowedswaps = {(0,1),(2,3)}
  -> make the components as parents and look into that 
  -> here store the map of the frequency
  -> map<int,int>  => (component,{num->freq})

  Story Points :
  -> DSU -> find/union (rank/pathcom)
  -> unordered_map<int,unordered_map<int,int>>mp
  -> traverse the array
      int parent = find(i);
      groupFreq[parent][source[i]]++;
  -> hamming distance = 0;

  Please revise this question
*/
