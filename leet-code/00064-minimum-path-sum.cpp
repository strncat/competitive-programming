class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) { return 0; }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, std::vector<int>(n, 0));
        
        // base case
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // recurrence: min sum at i,j is the minimum of both dp[i-1][j] and dp[i][j-1]
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    // OR
    /*
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) { return 0; }
        vector<vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));
        int m = grid.size();
        int n = grid[0].size();
        // recurrence: min sum at i,j is the minimum of both dp[i-1][j] and dp[i][j-1]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j];

                // best route
                if (i > 0 && j > 0) {
                    dp[i][j] += std::min(dp[i-1][j], dp[i][j-1]);
                } else if (i > 0) {
                    dp[i][j] += dp[i-1][j];
                } else if (j > 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    */
}
};