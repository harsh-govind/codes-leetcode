class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, int &curr)
    {
        int m=grid.size(), n=grid[0].size();
        curr=curr+1;
        grid[i][j]=0;
        
        int dx[]={0, -1, 0, 1};
        int dy[]={-1, 0, 1, 0};
        
        for(int k=0; k<4; k++)
        {
            int newi=i+dx[k];
            int newj=j+dy[k];
            
            if(newi<m and newj<n and newi>=0 and newj>=0 and grid[newi][newj])
            {
                solve(grid, newi, newj, curr);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    int curr=0;
                    solve(grid, i, j, curr);
                    ans=max(curr, ans);
                }
            }
        }
        return ans;
    }
};