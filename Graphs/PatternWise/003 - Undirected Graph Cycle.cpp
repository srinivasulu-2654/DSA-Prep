/* 
  https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
  -> Here everything is same as dfs traversals just we are maintaining the parent of the current node becuase do not explore this again
*/

class Solution {
  public:
  
    bool checkCycle(vector<vector<int>>& adj,int u,vector<bool>&vis,int parent)
    {
        vis[u] = true;
        for(int v:adj[u])
        {
            if(v==parent) continue;
            
            if(vis[v]) return true;
            
            if(checkCycle(adj,v,vis,u)){
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && checkCycle(adj,i,vis,-1)){
                return true;
            }
        }
        
        return false;
    }
};
