//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      bool dfs(bool visited[], bool recVis[], int node, vector<int> adj[], bool check[])
        {
            visited[node]=true;
            recVis[node]=true;
            check[node]=false;
            for(auto &i:adj[node])
            {
                if(!visited[i])
                {
                    if(dfs(visited, recVis, i, adj, check))
                    {
                        check[node]=false;
                        return true;
                    }
                }
                else if(recVis[i])
                {
                    check[node]=false;
                    return true;
                }
            }
            
            check[node]=true;
            recVis[node]=false;
            return false;
        }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        bool visited[v]={false}, recVis[v]={false}, check[v]={false};
        
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
            {
                dfs(visited, recVis, i, adj, check);
            }
        }
        vector<int> ans;
        
        for(int i=0; i<v;i++)
        {
            if(check[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends