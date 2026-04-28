/*
  https://www.geeksforgeeks.org/problems/topological-sort/1
  
  -> So the main definition is "Linear ordering or vertices such that if there is an edge b/w u & v, "u appears before v in that ordering""
  -> so it is happening in only DAG (Directed Acylic Graph only)
  -> why only DAG :
      -> if there is undirected graph like this na 1----2 then it can go 1 to 2 and 2 to 1 so this order is wrong right
      -> why only Acyclic why not cyclic => if there will be like this 1->2->3->1 => order will be 1-2-3-1 so wrong
      
  -> Intution is store the vis array and if not vis mark as visited and expplore the dfs calls for that node
  -> while returing store in the stack of that node
*/

class Solution {
  public:
  
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,st);
            }
        }
        
        st.push(node); // while returning just push into the stack
        return;
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        stack<int>st;
        
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
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
