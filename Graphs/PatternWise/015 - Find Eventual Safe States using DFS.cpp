/* 
  -> This is same as the detect the cycles in directed graph
  -> so the thing is terminology like safe and terminal
  -> the nodes are safe if the terminal (means dead end node) should not have the edges (means no outdegree edges)
  -> called as safe node

  -> ****** Another important point is :
      -> Anyone who is the part of the cycle is not safe nodes
      -> anyone that leads to a cycle cannot be the safe nodes

  -> soo same as the detect cycle code only but we have to carry one vector which is "check"
  -> so at last of the function if it didn't have cycle then check[node] = 1
  
*/

class Solution {
public:

    bool dfs(int node,vector<vector<int>> &graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0; // initially mark it as 0 as it might get cycle
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,graph,vis,pathVis,check) == true)
                {
                    check[node] = 0; // here cycles may detect right 
                    return true;
                }
            }
            else if(vis[it] && pathVis[it])
            {
                check[node] = 0; // here cycles may detect right
                return true;
            }
        }
        
        check[node] = 1; // at last if it is not cycle then that node will mark it as 1
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>pathVis(V,0);
        vector<int>vis(V,0);
        vector<int>check(V,0);
        vector<int>safeNodes;

      
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
