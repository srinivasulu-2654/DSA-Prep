https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int>&vis,vector<int>&pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis) == true) return true;
            }
            else if(vis[it] && pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<int>pathVis(V,0);
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathVis) == true) return true;
            }
        }
        
        return false;
    }
};
