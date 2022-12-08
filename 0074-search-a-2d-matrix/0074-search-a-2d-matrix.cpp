class Solution
{
    public:
        int isPresent(vector<int> &v, int key)
        {
            int s = 0;
            int e = v.size() - 1;
            int mid;
            bool ans = false;
            while (s <= e)
            {
                mid = (s + e) / 2;
                if (v[mid] == key)
                {
                    ans = true;
                    return ans;
                }
                else if (v[mid] > key)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        }
    bool searchMatrix(vector<vector < int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target and target <= matrix[i][n - 1])
            {
                vector<int> temp;

                for (int j = 0; j < n; j++)
                {
                    cout << matrix[i][j] << " ";
                    temp.push_back(matrix[i][j]);
                }

                return isPresent(temp, target);
            }
        }
        return 0;
    }
};