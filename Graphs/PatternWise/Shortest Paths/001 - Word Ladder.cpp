/*
  https://leetcode.com/problems/word-ladder/description/
  => The main theme here is 1 begin word and 1 end word and wordlist given
    => we have to take the reference of the wordlist then change single letter of each word
    => make the shortest distance to reach the end word and then return the level of where this is been acheieving

  => Steps we have to perform:
      1. Take Queue and push the beginWord with level of 1 {beginWord,1}
      2. pop the front and explore the paths means for example: cat is there then 1st letter need to explore from 'a' to 'z' and second,third
      3. if we got the word like this na "cag" if it is in wordList then remove in wordList and add it in queue with level + 1
      4. why we are removing in starting itslef na if we want to travel from 
          -> kolkata -> odihsa -> bengaluru -> hyderabad
          -> kolkata -> bengaluru -> odisha -> hyder  => already odisha visited right why we need to go back again


    TC : O(N) * O(word.size() * 26) * O(log N) 
   i means here list lenght to traverse * internal word size * 26 * to find in set for particular word
*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++)
            {
                char orginalChar = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }

                word[i] = orginalChar;
            }
        } 

        return 0;
    }
};
