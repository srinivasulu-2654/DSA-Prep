/* 
  -> Here what we are doing na :
    -> we have already did that topological sorting right
    -> actually topological sorting can happens only in DAG(directed Acyclic Graph) only
    -> at last topo.size() == V then it didn't have cycles 
    -> but if topo.size() != V then it can have cycles we can return true;
    -> the thing is here if indegree[i] == 0 then will pop that node from queue explore the adjacent nodes
    -> if that indegree[it]-- if indegree[it] == 0 then only we have to push and queue also wont become empty
    -> here if cycles is there na indegree[it]-- and indegree[it] wont become '0'
    -> then topo sort answer can get not exactly equals to V
    -> we can copy paste the same code of topological sort
    -> instead vector we can track the cnt = 0;
*/

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cnt == V) return false;
        return true;
    }
};
