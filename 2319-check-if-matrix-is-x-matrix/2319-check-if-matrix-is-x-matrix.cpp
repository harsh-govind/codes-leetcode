class Solution
{
    public:
        bool checkXMatrix(vector<vector < int>> &grid)
        {
            int m = grid.size();

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == j or i + j == m - 1)
                    {
                        if (grid[i][j] == 0)
                        {
                            cout << "first";
                            return false;
                        }
                    }
                    else
                    {
                        if (grid[i][j] != 0)
                        {

                            cout << "second" << " " << i << " " << j;

                            return false;
                        }
                    }
                }
            }
            return true;
        }
};