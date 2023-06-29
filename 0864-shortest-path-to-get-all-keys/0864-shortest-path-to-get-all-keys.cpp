class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int allKeys = 0;
        int startX = -1, startY = -1;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                } else if (islower(grid[i][j])) {
                    allKeys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(64, 0)));
        queue<State> q;
        q.push(State(startX, startY, 0));
        visited[startX][startY][0] = 1;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                State curr = q.front();
                q.pop();

                if (curr.keys == allKeys) {
                    return steps;
                }

                for (const auto& dir : directions) {
                    int newX = curr.x + dir[0];
                    int newY = curr.y + dir[1];
                    int newKeys = curr.keys;

                    if (newX < 0 || newX >= m || newY < 0 || newY >= n ||
                        grid[newX][newY] == '#' || visited[newX][newY][newKeys]) {
                        continue;
                    }

                    char c = grid[newX][newY];
                    if (islower(c)) {
                        newKeys |= (1 << (c - 'a'));
                    } else if (isupper(c) && !(newKeys & (1 << (c - 'A')))) {
                        
                        continue;
                    }

                    q.push(State(newX, newY, newKeys));
                    visited[newX][newY][newKeys] = 1;
                }
            }
            steps++;
        }

        return -1;  
    }
private:
    struct State {
        int x, y;  // Current position
        int keys;  // Bitmask representing acquired keys

        State(int x, int y, int keys) : x(x), y(y), keys(keys) {}
    };
};

