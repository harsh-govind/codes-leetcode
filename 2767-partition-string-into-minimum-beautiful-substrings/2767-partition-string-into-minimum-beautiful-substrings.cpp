class Solution {
public:
    long long gen(string s, int l, int r)
{
    long long num = 0;
    for (int i = l; i < r; i++)
    {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}
bool check(long long num)
{

    if (num < 125)
    {
        return (num == 1 || num == 5 || num == 25);
    }
    if (num % 125 != 0)
    {
        return false;
    }
    else
    {
        return check(num / 125);
    }
}
int minimumBeautifulSubstrings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1);
    for (auto &val : dp)
    {
        val = n + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1')
        {
            for (int j = 0; j < i; j++)
            {
                if (s[j] == '1')
                {
                    long long num = gen(s, j, i);
                    if (!check(num))
                        continue;

                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    return dp[n] == n + 1 ? -1 : dp[n];
}
};