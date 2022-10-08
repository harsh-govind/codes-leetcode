class Solution
{
    public:
        bool validateSubboard(vector<vector < char>> &board)
        {
            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 9; j += 3)
                {
                    unordered_map<char, int> m;
                    for (int a = i; a < i + 3; a++)
                    {
                        for (int b = j; b < j + 3; b++)
                        {
                            if (!((board[a][b] >= '1'
                                    and board[a][b] <= '9') or board[a][b] == '.'))
                            {
                                return false;
                            }
                            m[board[a][b]]++;
                        }
                    }
                    for (auto &val: m)
                    {
                        if (val.first != '.'
                            and val.second > 1)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    bool validRow(vector<vector < char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> m;

            for (int j = 0; j < 9; j++)
            {
                m[board[i][j]]++;
            }
            for (auto &val: m)
            {
                if (val.first != '.'
                    and val.second > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool validColumn(vector<vector < char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> m;

            for (int j = 0; j < 9; j++)
            {
                m[board[j][i]]++;
            }
            for (auto &val: m)
            {
                if (val.first != '.'
                    and val.second > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector < char>> &board)
    {
        return validColumn(board) and validRow(board) and validateSubboard(board);
    }
};