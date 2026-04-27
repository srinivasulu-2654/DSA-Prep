/* 
  -> Bipartite Graph means -> color the graph with 2 colors such that no two adjacent nodes have the same color
  -> linear graph with no cycle always a Bipartite Graph
  -> Graph with even number of cycles is alwasys a - Bipartite Graph
  -> Graph with odd number of cycles is alwasys a - not Bipartite Graph
*/

class Solution {
public:
     bool bfs(int node,int V,vector<vector<int>> &graph,vector<int>&colour)
    {
       
        queue<int>q;
        q.push(node);
        colour[node] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int prevColor = colour[node];
            
            for(auto it : graph[node])
            {
                // if the adjacent node is not yet colored 
                // you can color the opposite of the color node
                if(colour[it] == -1)
                {
                    colour[it] = !prevColor;
                    q.push(it);
                }
                // if the node and it have the same color retrun false;
                else if(colour[it] == prevColor) return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>colour(V,-1);
        
        
        for(int i=0;i<V;i++)
        {
            if(colour[i]==-1)
            {
                if(bfs(i,V,graph,colour) == false) return false;
            }
        }
        
        return true;
    }
};
