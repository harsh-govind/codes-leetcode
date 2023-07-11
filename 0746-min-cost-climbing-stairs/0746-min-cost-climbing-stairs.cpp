class Solution
{
    public:
        int solve(int n, vector<int> &cost, vector<int> &dp)
        {
            if (n == 1 or n == 0) return cost[n];

            if(dp[n]!=-1) return dp[n];
            
            int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp)) + cost[n];
            return dp[n]=ans;
        }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n+2, -1);
        int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
        return ans;
    }
};