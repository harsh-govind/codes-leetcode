class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        
        // Create a DP array to store minimum path sums
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Initialize the DP array with the values from the bottom row
        for (int i = 0; i < m; i++) {
            dp[m - 1][i] = grid[m - 1][i];
        }
        
        // Start from the second-to-last row and work upwards
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Calculate the minimum path sum for each cell
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        
        // The minimum path sum will be at the top of the DP array
        return dp[0][0];
    }
};
