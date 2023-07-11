class Solution
{
    public:
        int solve(string &a, string &b, int i, int j, vector<vector < int>> &dp)
        {
            if (i == a.size()) return b.size() - j;
            if (j == b.size()) return a.size() - i;

            if (dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            if (a[i] == b[j])
            {
                return solve(a, b, i + 1, j + 1, dp);
            }
            else
            {
                int insertElement = 1 + solve(a, b, i, j + 1, dp);
                int deleteElement = 1 + solve(a, b, i + 1, j, dp);
                int replaceElement = 1 + solve(a, b, i + 1, j + 1, dp);

                ans = min(insertElement, min(deleteElement, replaceElement));
            }

            return dp[i][j] = ans;
        }
    int minDistance(string a, string b)
    {
        vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
        return solve(a, b, 0, 0, dp);
    }
};