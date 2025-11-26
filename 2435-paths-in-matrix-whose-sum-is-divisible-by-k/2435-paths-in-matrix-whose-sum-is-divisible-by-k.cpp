class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][r] = number of ways to reach cell (i, j) with remainder r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int r = 0; r < k; ++r) {
                    if (dp[i][j][r] == 0) continue;

                    int curr = dp[i][j][r];

                    // Move Down
                    if (i + 1 < m) {
                        int newR = (r + grid[i+1][j]) % k;
                        dp[i+1][j][newR] = (dp[i+1][j][newR] + curr) % MOD;
                    }

                    // Move Right
                    if (j + 1 < n) {
                        int newR = (r + grid[i][j+1]) % k;
                        dp[i][j+1][newR] = (dp[i][j+1][newR] + curr) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0]; // remainder 0 means divisible by k
    }
};
