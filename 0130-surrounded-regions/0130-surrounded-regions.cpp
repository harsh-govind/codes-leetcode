class Solution {
public:
    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        visited[i][j] = true;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && !visited[newi][newj] && board[newi][newj] == 'O') {
                dfs(visited, board, newi, newj);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && !visited[i][j] && board[i][j] == 'O') {
                    dfs(visited, board, i, j);
                }
            }
        }

        // Replace remaining 'O's that are not connected to the border with 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

        // Restore previously marked 'K's to 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'K') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
