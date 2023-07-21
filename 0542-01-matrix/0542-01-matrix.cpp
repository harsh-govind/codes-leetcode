class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Separate visited array
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true; // Mark as visited
                }
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[row][col] = dist;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, dist + 1});
                    visited[nrow][ncol] = true; // Mark as visited
                }
            }
        }
        return ans;
    }
};
