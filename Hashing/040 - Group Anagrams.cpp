Approach 1 :

/* 
  -> sort and use map store the vector of string in the coresponded sorted string
  -> strs = ["eat","tea","tan","ate","nat","bat"] 
  -> aet -> {ate,tea,eat}
     ant -> {nat,tan}
     abt -> {bat} like this store and add into the vector of the strings
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

O(k) * O(nlogn)

Approach 2 :

/*
  -> for the above approach we have done like sorting k * nlogn in this no need to sort
  -> steps:
      -> first take for each internal word and put it in a 26 sized char array
      -> and then make the new_word = "" traverse again the new array and store which is non-zero
      -> then it will become sorted automatically and then store it in a map
      -> traverse map and store in the result array
      -> n * (k + 26) => n * k
*/

class Solution {
public:

    string generate(string &word)
    {
        int arr[26] = {0};
        for(char ch : word)
        {
            arr[ch-'a']++;
        }
        string new_word = "";
        for(int i=0;i<26;i++)
        {
            int freq = arr[i];
            if(freq > 0){ 
                new_word += string(freq,i+'a');
            }

        }

        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }

        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
