class Solution
{
    public:
    bool check(int row, int col, vector<vector < int>> &board, int n)
    {
        int x = row, y = col;
        while (y >= 0)
        {
            if (board[x][y--] == 1) return false;
        }
        x = row;
        y = col;
        while (x >= 0 and y >= 0)
        {
            if (board[x--][y--] == 1) return false;
        }
        x = row;
        y = col;
        while (x < n and y >= 0)
        {
            if (board[x++][y--] == 1) return false;
        }
        return true;
    }
    void solve(vector<vector < int>> &board, int n, int &ans, int col)
    {
        if (col == n)
        {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (check(row, col, board, n))
            {
                board[row][col] = 1;
                solve(board, n, ans, col + 1);
                board[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<vector < int>> board(n, vector<int> (n, 0));
        int ans=0;
        solve(board, n, ans, 0);
        return ans;
    }
};
