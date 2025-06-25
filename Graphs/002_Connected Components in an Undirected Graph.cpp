// same as 001

https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1


void dfs(int node, vector<vector<int>>&adj,vector<int>&temp,vector<int>&vis)
  {
      vis[node] = 1;
      
      temp.push_back(node);
      
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,temp,vis);
          }
          
      }
      
      return;
  }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj(V);
        
        vector<int>vis(V);
        
        vector<vector<int>>ans;
        
        // vector<int>temp;
        
        for(auto it: edges)
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
                vector<int>temp;
                dfs(i,adj,temp,vis);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
