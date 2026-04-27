class Solution {
public:
    bool dfs(int node,int preColor,vector<vector<int>>& graph,vector<int>&color)
    {
        color[node] = preColor;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!preColor,graph,color)==false) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,0,graph,color) == false) return false;
            }
        }

        return true;
    }
};
