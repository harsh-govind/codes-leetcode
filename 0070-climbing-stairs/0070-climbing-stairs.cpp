class Solution
{
    public:
        int solve(int i, int n, vector<int> &dp)
        {
            if (i == n) return 1;
            if (i > n) return 0;
            
            if(dp[i]!=-1) return dp[i];
            
            dp[i + 1] = solve(i + 1, n, dp);
            dp[i + 2] = solve(i + 2, n, dp);
            return dp[i + 1] + dp[i + 2];
        }
    int climbStairs(int n)
    {
        vector<int> dp(n + 2, -1);
        return solve(0, n, dp);
    }
};