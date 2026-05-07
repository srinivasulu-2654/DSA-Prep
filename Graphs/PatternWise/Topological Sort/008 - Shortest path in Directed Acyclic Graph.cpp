/* 
  https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
  -> so here we have to find the shortest distance of weight to reach the sorce node
  -> for that perform 2 steps:
      Step 1 : perform topological sorting
      step 2 : we have already stored the elements in stack
          -> in this take the array of distance with all the values of infinity 
          -> then from sorce node = 6 (ex) then pop the last node and do the traverse
          -> and store the better answer in the distance array that's it 
*/


// User function Template for C++

class Solution {
public:

    void dfs(int node,
             vector<int>& vis,
             vector<vector<pair<int,int>>>& adj,
             stack<int>& st)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            int v = it.first;

            if(!vis[v])
            {
                dfs(v, vis, adj, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        // create graph
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // topo sort using DFS
        vector<int> vis(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // distance array
        vector<int> dist(V, INT_MAX);

        // source node = 0
        dist[0] = 0;

        // process topo order
        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            // if node already reachable
            if(dist[node] != INT_MAX)
            {
                for(auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // unreachable nodes -> -1
        for(int i = 0; i < V; i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
