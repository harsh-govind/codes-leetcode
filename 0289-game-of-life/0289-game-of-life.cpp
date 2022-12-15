class Solution
{
    public:
        void gameOfLife(vector<vector < int>> &board)
        {
            int n = board.size();
            int m = board[0].size();
            int dx[] = { 0,
                0,
                1,
                -1,
                1,
                1,
                -1,
                -1
            };
            int dy[] = { 1,
                -1,
                0,
                0,
                1,
                -1,
                1,
                -1
            };
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && (board[x][y] == 1 || board[x][y] == 2))
                        {
                            cnt++;
                        }
                    }
                    if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
                    {
                        board[i][j] = 2;
                    }
                    else if (board[i][j] == 0 && cnt == 3)
                    {
                        board[i][j] = 3;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    board[i][j] %= 2;
                }
            }
        }
};