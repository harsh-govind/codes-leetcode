class Solution {
public:
    bool check(int i, int j, vector<vector<char>>& graph, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n and graph[i][j]=='1';
    }
    void dfs(vector<vector<char>>& graph, int i, int j, int m, int n)
    {
        graph[i][j] = '0';
        
        
        int dx[8] = { -1,  0, 1, 0};
        int dy[8] = { 0, 1, 0, -1};
        
        for(int k=0; k<4; k++)
        {
            if(check(i+dx[k], j+dy[k], graph, m, n))
            {
                dfs(graph, i+dx[k], j+dy[k], m, n);
            }
        }        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
};