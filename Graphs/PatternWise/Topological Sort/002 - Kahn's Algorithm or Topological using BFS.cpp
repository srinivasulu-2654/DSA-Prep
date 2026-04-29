/* 
  -> so the logic for this algorithm is:
    -> we have to first make the indegree array
    -> at first if the indegree[node] = 0 then push into the queue
    -> pop each node and check it's outdegree make them to indegree[node_outdegree] = -1;
    -> indegree array can make from the given edges matrix
    -> 
*/

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
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
        
        return topo;
    }
};
