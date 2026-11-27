class Solution {
public:
    void bfs(int i, int j,vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;

        vis[i][j] = true;
        q.push({i,j});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // top to the grid
            if(r-1>=0 && grid[r-1][c] == '1' && vis[r-1][c] == false)
            {
                vis[r-1][c] = true;
                q.push({r-1, c});

            }
            // bottom to the current grid
            if(r+1 <n && grid[r+1][c] == '1' && vis[r+1][c] == false)
            {
                vis[r+1][c] = true;
                q.push({r+1, c});
            }
            // left to the current 
            if(c-1>=0 && grid[r][c-1] == '1' && vis[r][c-1] == false)
            {
                vis[r][c-1] = true;
                q.push({r,c-1});
            }
            // right to the current 
            if(c+1<m && grid[r][c+1] == '1' && vis[r][c+1] == false)
            {
                vis[r][c+1] = true;
                q.push({r,c+1});
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && !(vis[i][j]))
                {
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};