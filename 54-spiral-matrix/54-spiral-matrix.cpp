class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            int k = 0;
            vector<int> ans;
            int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
            while (ans.size() < matrix.size() *matrix[0].size())
            {
                for (int i = l; i <= r and ans.size() < matrix.size() *matrix[0].size(); i++)
                {
                    ans.push_back(matrix[u][i]);
                    k++;
                }
                u++;
                for (int i = u; i <= d and ans.size() < matrix.size() *matrix[0].size(); i++)
                {
                    ans.push_back(matrix[i][r]);
                    k++;
                }
                r--;
                for (int i = r; i >= l and ans.size() < matrix.size() *matrix[0].size(); i--)
                {
                    ans.push_back(matrix[d][i]);
                    k++;
                }
                d--;
                for (int i = d; i >= u and ans.size() < matrix.size() *matrix[0].size(); i--)
                {
                    ans.push_back(matrix[i][l]);
                    k++;
                }
                l++;
            }
            return ans;
        }
};