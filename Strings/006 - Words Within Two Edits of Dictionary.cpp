https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22

/*
    -> We can directly check this and will do using for loop as time constraints are less only
    -> TC : O(q) * O(d) * O(n)
    -> q-> queries length , d = dictionary lenght, n -> queryies internal query length

    -> Follow up question will be :
        -> why should not solve this by "trie"
        -> "trie" only preferred for prefix kind of things
        -> but here we want to check entire word not only prefix
        -> (here if we use trie it will take space as well as time complexity more)
        -> Please explore the trie part
*/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string>res;
        for(string q : queries)
        {
            for(string s:dictionary)
            {
                int diff = 0;
                for(int i=0;i<q.size();i++)
                {
                    if(q[i]!=s[i])
                    {
                        diff++;
                    }

                    if(diff>2) break;
                }

                if(diff<=2)
                {
                    res.push_back(q);
                    break;
                }
            }
        }

        return res;
    }
};
