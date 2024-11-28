https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-elements-by-its-rank-in-the-array


vector<int> replaceWithRank(vector<int> &arr, int N){

          vector<int>ans(N,0);
          
          unordered_map<int,int>mp;
          
          vector<int>sortedArray = arr;
          sort(sortedArray.begin(),sortedArray.end());
          
          int rank = 1;
          
          for(int i=0;i<N;i++)
          {
              if(mp.find(sortedArray[i]) == mp.end())
              {
                  mp[sortedArray[i]] = rank++;
              }
          }
          
          
         for(int i=0;i<N;i++)
         {
             ans[i] = mp[arr[i]];
         }
         
         return ans;
    }
