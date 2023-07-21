//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[], bool visited[], int node, int parent)
    {
        visited[node]=true;
        queue<pair<int, int>> q;
        q.push({node, -1});
        
        while(!q.empty())
        {
            int tnode=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto &adjacentNode:adj[tnode])
            {
                if(!visited[adjacentNode])
                {
                    visited[adjacentNode]=true;
                    q.push({adjacentNode, tnode});
                }
                else if(parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        bool visited[v]={false};
        
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
            {
                if(bfs(adj, visited, i, -1)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends