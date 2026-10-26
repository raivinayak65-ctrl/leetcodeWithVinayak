class Solution {
private:
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        
        long long currentVal = grid[r][c];
        grid[r][c] = 0; 
        
        currentVal += dfs(grid, r + 1, c);
        currentVal += dfs(grid, r - 1, c);
        currentVal += dfs(grid, r, c + 1);
        currentVal += dfs(grid, r, c - 1);
        
        return currentVal;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long totalSum = dfs(grid, i, j);
                    if (totalSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};