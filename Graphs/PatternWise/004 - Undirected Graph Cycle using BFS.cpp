class Solution {
  public:
  
    bool bfs(int node,vector<vector<int>>&adj,vector<bool>&vis)
    {
        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node] = true;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int source = it.first;
            int parent = it.second;
            
            for(int &v:adj[source]){
                if(vis[v] == false)
                {
                    vis[v] = true;
                    q.push({v,source});
                }
                else if(v != parent)
                {
                    return true;
                }
            }
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
                if(bfs(i,adj,vis) == true) return true;
            }
        }
        
        return false;
        
    }
};
