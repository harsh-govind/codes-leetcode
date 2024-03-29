class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            vector<int> ans;
            int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
            while (l <= r and u <= d)
            {
                for (int i = l; i <= r and l <= r and u <= d; i++)
                {
                    ans.push_back(matrix[u][i]);
                }
                u++;
                for (int i = u; i <= d and l <= r and u <= d; i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
                for (int i = r; i >= l and l <= r and u <= d; i--)
                {
                    ans.push_back(matrix[d][i]);
                }
                d--;
                for (int i = d; i >= u and l <= r and u <= d; i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            return ans;
        }
};