class Solution
{
    public:
        int countSubstrings(string S)
        {
            int N = S.size();
            vector<vector < int>> dp(N, vector<int> (N, 0));
            int ans = 0;

            for (int diff = 0; diff < N; diff++)
            {
                for (int i = 0, j = diff; j < N && i < N; i++, j++)
                {
                    if (diff == 0)
                        dp[i][j] = 1;
                    else if (diff == 1)
                    {
                        if (S[i] == S[j])
                            dp[i][j] = 1;
                    }
                    else
                    {
                        if (S[i] == S[j] && dp[i + 1][j - 1] == 1)
                            dp[i][j] = 1;
                    }

                    if (dp[i][j] == 1)
                        ans++;
                }
            }
            return ans;
        }
};