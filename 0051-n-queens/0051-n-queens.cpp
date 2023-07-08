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
    void solve(vector<vector < int>> &board, int n, vector< vector< string >> &ans, int col, unordered_map< int, int> &upperDiagonal, unordered_map< int, int> &roww, unordered_map< int, int> &lowerDiagonal)
    {
        if (col == n)
        {
            addSolution(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (upperDiagonal.find((n - 1) + (col - row)) == upperDiagonal.end() and roww.find(row) == roww.end() and lowerDiagonal.find(row + col) == lowerDiagonal.end())
            {
                upperDiagonal[(n - 1) + (col - row)] = true;
                roww[row] = true;
                lowerDiagonal[row + col] = true;
                board[row][col] = 1;
                solve(board, n, ans, col + 1, upperDiagonal, roww, lowerDiagonal);
                board[row][col] = 0;
                upperDiagonal.erase((n - 1) + (col - row));
                roww.erase(row);
                lowerDiagonal.erase(row + col);
            }
        }
    }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < int>> board(n, vector<int> (n, 0));
        vector<vector < string>> ans;
        unordered_map<int, int> roww, upperDiagonal, lowerDiagonal;
        //upper diagonal -> (n-1)+(col-row)
        //row -> row
        //lower diagonal -> (row+col)
        solve(board, n, ans, 0, upperDiagonal, roww, lowerDiagonal);
        return ans;
    }
};