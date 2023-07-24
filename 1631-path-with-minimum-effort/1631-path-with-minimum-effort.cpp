class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0]=0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            if (row == m - 1 && col == n - 1)
                return diff;
            
             int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++)
            {
                int newRow=row+dr[i];
                int newCol=col+dc[i];
                
                if(newRow<m and newRow>=0 and newCol<n and newCol>=0)
                {
                    int newEffort=max(abs(heights[row][col]-heights[newRow][newCol]), diff);
                    
                    if(newEffort<dist[newRow][newCol])
                    {
                        dist[newRow][newCol]=newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
        
    }
};