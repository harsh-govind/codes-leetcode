class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {
            int l = 0, r = n - 1, u = 0, d = n - 1, temp = 1;
            vector<vector < int>> finalAns;
            for (int i = 0; i < n; i++)
            {
                vector<int> t;
                for (int j = 0; j < n; j++)
                {
                    t.push_back(0);
                }
                finalAns.push_back(t);
            }
            while (l <= r and u <= d)
            {
                for (int i = l; i <= r and l <= r and u <= d; i++)
                {
                    finalAns[u][i] = temp++;
                }
                u++;
                for (int i = u; i <= d and l <= r and u <= d; i++)
                {
                    finalAns[i][r] = temp++;
                }
                r--;
                for (int i = r; i >= l and l <= r and u <= d; i--)
                {
                    finalAns[d][i] = temp++;
                }
                d--;
                for (int i = d; i >= u and l <= r and u <= d; i--)
                {
                    finalAns[i][l] = temp++;
                }
                l++;
            }

            return finalAns;
        }
};