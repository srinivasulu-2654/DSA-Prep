/*
  -> here first we want to take queue,vis,and bfs to store answers
  -> here for each and every node we have to point out the neighbours of the node
  -> if not visited mark as visited and push into the queue;

   TC : O(n) + O(2*E) => because total degree of graph => 2 * edges
*/


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>vis(n,0);
        vector<int>bfs;
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node])
            {
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};
