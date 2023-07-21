class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                } else {
                    // Mark non-zero cells as visited with a unique value
                    mat[i][j] = -1;
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
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && mat[nrow][ncol] == -1) {
                    q.push({{nrow, ncol}, dist + 1});
                    // Mark the cell as visited by setting it to a non-zero value
                    mat[nrow][ncol] = -2;
                }
            }
        }
        return ans;
    }
};
