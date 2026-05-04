/* 
  -> actually in some problems there will be like this :
      adj[v].push_back(u); or like below
      adj[u].push_back(v);

  -> if we want to perform v then perform u first
  -> if we want to perform u then perform v first
*/


class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[v].push_back(u); // so according to striver we have to take here reverse
        }
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
        
       if (topo.size() != V) return {};
       return topo;
    }
};
