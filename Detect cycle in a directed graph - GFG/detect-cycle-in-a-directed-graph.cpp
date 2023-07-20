//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(bool visited[], bool recVis[], int node, vector<int> adj[])
    {
        visited[node]=true;
        recVis[node]=true;
        
        for(auto &i:adj[node])
        {
            if(!visited[i])
            {
                if(dfs(visited, recVis, i, adj)) return true;
            }
            else if(recVis[i])
            {
                return true;
            }
        }
        
        recVis[node]=false;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        bool visited[v]={false}, recVis[v]={false};
        
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
            {
                if(dfs(visited, recVis, i, adj)) return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends