class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j, int m, vector<vector<int>> &dp)
    {
       if(i>=m or i<0) return 1e6;

        int n=grid[i].size();
        
        if(j>=n or j<0) return 1e6;
        
        if(i==m-1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=1e6, dig=1e6;
        
        down=grid[i][j]+solve(grid, i+1, j, m, dp);
        dig=grid[i][j]+solve(grid, i+1, j+1, m, dp);
        
        return dp[i][j]=min(down, dig);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m=grid.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));
        return solve(grid, 0, 0, m, dp);
    }
};