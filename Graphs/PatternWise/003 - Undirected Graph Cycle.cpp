/* 
  https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
  -> Here everything is same as dfs traversals just we are maintaining the parent of the current node becuase do not explore this again
*/

class Solution {
  public:
  
    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[node] = true;
        for(auto it:adj[node])
        {
            if(!vis[it]){
                if(dfs(it,node,adj,vis) == true) return true;
            }
            else if(it != parent) return true;
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        vector<bool>vis(V,false);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis) == true) return true;
            }
        }
        
        return false;
        
    }
};
