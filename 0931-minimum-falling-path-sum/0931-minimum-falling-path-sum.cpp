class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans=INT_MAX;
        
        for(int l=0; l<n; l++)
        {
            dp[0][l]=grid[0][l];
        }
            for(int i=1; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    int upLeft=1e6, up=1e6, upRight=1e6;
                    
                    if(i-1>=0)
                    {
                        up=grid[i][j]+dp[i-1][j];
                    }
                    
                    if(i-1>=0 and j-1>=0)
                    {
                        upLeft=grid[i][j]+dp[i-1][j-1];
                    }
                    
                    if(i-1>=0 and j+1<n)
                    {
                        upRight=grid[i][j]+dp[i-1][j+1];
                    }
                    
                    dp[i][j]=min(min(upRight, upLeft), up);
                }
            }
        
        for(int i=0; i<n; i++)
        {
            ans=min(ans, dp[m-1][i]);
        }
        return ans;
    }
};