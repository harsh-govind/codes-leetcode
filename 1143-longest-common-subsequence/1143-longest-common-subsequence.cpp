class Solution
{
    public:
        int lcs(string a, string b, int m, int n)
        {
            int t[m + 1][n + 1];
            for (int i = 0; i < n + 1; i++)
            {
                t[0][i] = 0;
            }
            for (int i = 0; i < m + 1; i++)
            {
                t[i][0] = 0;
            }

            for (int i = 1; i < m + 1; i++)
            {
                for (int j = 1; j < n + 1; j++)
                {
                    if (a[i - 1] == b[j - 1])
                    {
                        t[i][j] = 1 + t[i - 1][j - 1];
                    }
                    else
                    {
                        t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                    }
                }
            }
            return t[m][n];
        }
    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, text1.size(), text2.size());
    }
};