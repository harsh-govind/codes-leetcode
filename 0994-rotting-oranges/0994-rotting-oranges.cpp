class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int vis[m][n], freshCount=0;
        
        //{{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i, j}, 0});
                }
                else 
                {
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1)
                {
                    freshCount++;
                }
            }
        }
        int deltaRow[]={-1, 0, +1, 0}, deltaColumn[]={0, 1, 0, -1}, count=0, time=0;
        
        while(!q.empty())
        {
            pair<pair<int, int>, int> temp=q.front();
            q.pop();
            
            int row=temp.first.first, column=temp.first.second, t=temp.second;
            
            time = max(time, t);
            
            for(int k=0; k<4; k++)
            {
                int newRow=row+deltaRow[k], newColumn=column+deltaColumn[k];
                
                if(newRow>=0 and newRow<m and newColumn>=0 and newColumn<n and vis[newRow][newColumn]==0 and grid[newRow][newColumn]==1)
                {
                    q.push({{newRow, newColumn}, t+1});
                    vis[newRow][newColumn]=2;
                    count++;
                }
            }
        }
        
        return count==freshCount?time:-1;
        
        
    }
};