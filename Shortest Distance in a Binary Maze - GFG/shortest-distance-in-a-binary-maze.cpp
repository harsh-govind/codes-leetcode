//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first==destination.first && source.second==destination.second) 
            return 0; 
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[source.first][source.second];
        q.push({0, {source.first, source.second}});
        int dr[]={0, -1, 0, 1};
        int dc[]={1, 0, -1, 0};
        
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            int dis=front.first;
            int r=front.second.first;
            int c=front.second.second;
            
            for(int i=0; i<4; i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1 and dis+1<dist[nr][nc])
                {
                    dist[nr][nc]=1+dis;
                    if(nr==destination.first and nc==destination.second)
                    {
                        return dis+1;
                    }
                    q.push({dis+1,{nr, nc}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends