class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {
            vector<int> check(n + 1);

            for (int i = 0; i < trust.size(); i++)
            {
                check[trust[i][0]]--;
                check[trust[i][1]]++;
            }

            for (int i = 1; i <= n; i++)
            {
                if (check[i] == n - 1)
                {
                    return i;
                }
            }

            return -1;
        }
};