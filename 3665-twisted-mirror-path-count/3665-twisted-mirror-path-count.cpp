

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rightDest(m, vector<int>(n, -1));
        vector<vector<int>> downDest(m, vector<int>(n, -1));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int pos = i * n + j;

                if (grid[i][j] == 0) {
                    rightDest[i][j] = pos;
                    downDest[i][j] = pos;
                } else {
                    if (i + 1 < m) {
                        rightDest[i][j] = downDest[i + 1][j];
                    }

                    if (j + 1 < n) {
                        downDest[i][j] = rightDest[i][j + 1];
                    }
                }
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0 || grid[i][j] == 1) {
                    continue;
                }

                int ways = dp[i][j];

                if (j + 1 < n) {
                    int dest = rightDest[i][j + 1];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + (long long)ways) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int dest = downDest[i + 1][j];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + (long long)ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
