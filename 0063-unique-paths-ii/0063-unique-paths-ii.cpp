class Solution
{
    public:
        int solve(vector<vector < int>> &grid, int i, int j, int m, int n, vector< vector< int>> &dp)
        {
            if (i < 0 or i >= m or j < 0 or j >= n) return 0;

            if (grid[i][j] == 1) return 0;

            if (i == m - 1 and j == n - 1) return 1;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            ans += solve(grid, i + 1, j, m, n, dp);
            ans += solve(grid, i, j + 1, m, n, dp);
            return dp[i][j] = ans;
        }
    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector < int>> dp(m, vector<int> (n, -1));
        return solve(grid, 0, 0, m, n, dp);
    }
};