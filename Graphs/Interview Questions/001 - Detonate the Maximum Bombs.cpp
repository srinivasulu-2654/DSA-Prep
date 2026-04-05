/*
  -> This question was asked in my amazon interview sde 1 on 3 April 2026
  -> I was literally blank by seeing this question
  -> main approach is if we choose 1 bomb to detonate then how many maximum bombs will detonate we have to return that
  -> so if there are to bombs in different radius for that we have to calculate the distance d
  -> if r >= d then only if we detonate 1 bomb it will effect other too also 
  -> Why Graph problem ? : ************ IMPORTANT ***************
  -> let's say we have bombs b1,b2,b3,b4 like that
  -> then we used to make adjacency list in graph right?
  -> hence if B1 -> {B2,B3}, B2 -> {B4,B5}
  -> another question will it be directed or undirected (that's why directed graph only -> check below 2 points)
  -> if b1 in the radius b2 also there then both will blast
  -> if b1 is not in the radius of b2 then b2 radius < b1 radius => then only b2 will blast
  -> we are visiting  the nodes
  -> no. of nodes you are able to visit from a given node = detonate count
  -> in question we have blast only 1 bomb then from that bomb how many maximum will blast
  -> so we have to call each bomb to the dfs or bfs then caluclate among the maximum
*/

DFS :

class Solution {
public:
    typedef long long ll;
    void dfs(int u,unordered_set<int>&vis,unordered_map<int,vector<int>>&adj)
    {
        vis.insert(u);
        for(int v:adj[u]){
            if(vis.find(v)==vis.end())
            {
                dfs(v,vis,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll distance = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
                if(r1*r1 >= distance)
                {
                    adj[i].push_back(j);
                }

            }
        }

        int res = 0;
        unordered_set<int>vis;
        for(int i=0;i<n;i++)
        {
            dfs(i,vis,adj);
            int cnt = vis.size();
            res = max(cnt,res);
            vis.clear(); // should clear for each and eve
        }

        return res;
    }
};

BFS :

class Solution {
public:
    typedef long long ll;
    int bfs(int u,unordered_map<int,vector<int>>&adj)
    {
        unordered_set<int>vis;
        queue<int>q;
        q.push(u);
        vis.insert(u);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(int v:adj[temp])
            {
                if(vis.find(v) == vis.end())
                {
                    vis.insert(v);
                    q.push(v);
                }
            }
        }

        return vis.size();
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll distance = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
                if(r1*r1 >= distance)
                {
                    adj[i].push_back(j);
                }

            }
        }

        int res = 0;
        unordered_set<int>vis;
        for(int i=0;i<n;i++)
        {
            int cnt = bfs(i,adj);
            res = max(cnt,res);
            vis.clear(); // should clear for each and eve
        }

        return res;
    }
};
