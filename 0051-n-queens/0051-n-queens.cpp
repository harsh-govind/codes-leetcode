class Solution
{
    public:
        void addSolution(vector<vector < int>> &board, vector< vector< string>> &ans, int n)
        {
            vector<string> temp;
            for (int i = 0; i < n; i++)
            {
                string temp1;
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                    {
                        temp1.push_back('Q');
                    }
                    else
                    {
                        temp1.push_back('.');
                    }
                }
                temp.push_back(temp1);
            }
            ans.push_back(temp);
        }
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
    void solve(vector<vector < int>> &board, int n, vector< vector< string>> &ans, int col)
    {
        if (col == n)
        {
            addSolution(board, ans, n);
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
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < int>> board(n, vector<int> (n, 0));
        vector<vector < string>> ans;
        solve(board, n, ans, 0);
        return ans;
    }
};