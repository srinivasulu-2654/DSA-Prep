/* 
  https://www.geeksforgeeks.org/problems/alien-dictionary/1
  -> here the thing is we have to return the string of length 'K'
  -> here they didn't gave any length of k
  -> so we have to generate the lenght if there is letters indicating a,b,c,d,e then we should generate the string size of 5 like that
  -> for this to generate k we have to take the present array where what are the letters are found like that
  -> and then tarverse of each first word and second word like that
  -> if first word of first and second letter different then make the direction that's it there graph generated
  -> then perform topological sorting enough
*/

class Solution {
  public:
    
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        
        queue<int>q;
        for(int i=0;i<V;i++)
        {
           if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;
    }
  
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>>adj(26);
        //the down line here they didn't gave the size of letters if k = 4 a,b,c,d like that so we are taking based on give strings
        vector<int>present(26,0); 
        for(auto word:words)
        {
            for(auto ch:word)
            {
                present[ch-'a'] = 1;
            }
        }
        
        
        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(),s2.size());
            bool flag = false;
            
            for(int ptr=0;ptr<len;ptr++)
            {
                if(s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    flag = true;
                    break;
                }
            }
            
            if(flag == false && s1.size()>s2.size()) return "";   // invalid case Eg: ["abc", "ab"]
        }
        
        
        
        vector<int>topo = topoSort(26,adj);
        string res = "";
        for(auto it:topo)
        {
            if(present[it] != 0)
            {
                char ch = it + 'a';
                res = res + ch;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<26;i++)
        {
            if(present[i] != 0) cnt++;
        }
        
        if(res.size() != cnt) return "";
        
        return res;
    }
};
