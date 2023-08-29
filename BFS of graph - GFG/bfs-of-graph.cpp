//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(unordered_map<int, bool> &visited, vector<int> &ans, int node, vector<int> adj[])
    {
        queue<int> q;
        q.push(node);
        visited[node]=true;
        
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto &neighbour:adj[frontNode])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        bfs(visited, ans, 0, adj);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends