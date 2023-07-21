//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, int row0, int col0, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &current)
    {
        visited[row][col]=1;
        current.push_back({row-row0, col-col0});
        int m=grid.size(), n=grid[0].size();
        int dx[]={1, 0, -1, 0};
        int dy[]={0, -1, 0, 1};
        
        for(int i=0; i<4; i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !visited[nrow][ncol] and grid[nrow][ncol]==1)
            {
                dfs(nrow, ncol, row0, col0, grid, visited, current);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] and grid[i][j]==1)
                {
                    vector<pair<int, int>> current;
                    dfs(i, j, i, j, grid, visited, current);
                    st.insert(current);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends