class Solution
{
    public:
        bool canPartition(vector<int> &arr)
        {
            int arrsum = accumulate(arr.begin(), arr.end(), 0), n = arr.size();

            if (arrsum % 2) return false;

            int sum = arrsum / 2;
            vector<vector < int>> dp(n + 1, vector<int> (sum + 1));
            for (int i = 0; i < sum + 1; i++)
            {
                dp[0][i] = false;
            }
            for (int i = 0; i < n + 1; i++)
            {
                dp[i][0] = true;
            }

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < sum + 1; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[n][sum];
        }
};