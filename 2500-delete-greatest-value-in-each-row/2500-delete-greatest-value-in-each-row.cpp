class Solution
{
    public:
        int deleteGreatestValue(vector<vector < int>> &grid)
        {
            for (auto &row: grid)
            {
                sort(row.begin(), row.end());
            }

            int ans = 0;

            for (int i = grid[0].size() - 1; i >= 0; i--)
            {
                int mx = INT_MIN;
                for (int j = 0; j < grid.size(); j++)
                {
                    mx = max(mx, grid[j][i]);
                }

                ans += mx;
            }

            return ans;
        }
};