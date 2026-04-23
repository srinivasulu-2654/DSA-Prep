Method 1 : DFS

class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>& image,int color,int iniColor){

        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
            {
                dfs(nrow,ncol,ans,image,color,iniColor);
            }
        }

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniColor = image[sr][sc];
        vector<vector<int>>ans = image;
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};

Method 2 : BFS

class Solution {
public:

    void bfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int iniColor)
    {
        queue<pair<int,int>>q;
         int m = image.size();
        int n = image[0].size();
        ans[row][col] = color;
        q.push({row,col});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                for(int i=0;i<4;i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
                    {
                        q.push({nrow,ncol});
                        bfs(nrow,ncol,ans,image,color,iniColor);
                    }
                } 
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        bfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};

