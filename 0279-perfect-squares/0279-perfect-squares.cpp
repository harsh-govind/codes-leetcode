class Solution
{
    public:
        int solve(int n, vector<int> &dp)
        {
            if (n <= 0) return 0;

            if (dp[n] != -1) return dp[n];
            int ans = n;

            for (int i = 1; i * i <= n; i++)
            {
                int temp = i * i;
                ans = min(ans, 1 + solve(n - temp, dp));
            }
            return dp[n] = ans;
        }

    int numSquares(int n)
    {
        vector<int> dp(n + 1, 999999);
        dp[0]=0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j*j<=n; j++)
            {
                int temp=j*j;
                if(i>=temp)
                    dp[i]=min(dp[i], dp[i-temp]+1);
            }
        }
        return dp[n];
    }
};