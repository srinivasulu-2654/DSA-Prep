class Solution {
  public:
  
  void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&ans)
  {
      ans.push_back(node);
      vis[node] = 1;
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,vis,ans);
          }
      }
      return;
  }
  
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>vis(n,0);
        int start = 0;
        vector<int>ans;
        dfs(start,adj,vis,ans);
        return ans;
        
    }
    
};
