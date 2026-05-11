/* 
  https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
  -> Steps for this :
      -> do simple bfs but instead vis take distance array with all infinity values
      -> make sure for each node it will be very less minimum value
      -> Here why only queue like that answers will rasie just look for that?
      -> why becuase we are getting the things like in queue the distance is already it will be in sorted order so that's why 
*/


class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        
        vector<vector<int>>adj(V);
        
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>dist(V,1e9);
        // for(int i=0;i<V;i++) dist[i] = 1e9;
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[node]+1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++)
        {
            if(dist[i] != 1e9) ans[i] = dist[i];
        }
        
        return ans;
    }
};
