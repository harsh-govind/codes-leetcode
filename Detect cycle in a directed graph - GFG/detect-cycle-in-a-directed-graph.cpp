//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
	void bfs(vector<int> adj[], int &ans, vector<int> &inDegree, int v)
	{
	    queue<int> q;
	    for(int i=0; i<v; i++)
	    {
	        if(inDegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans++;
	        
	        for(auto &i:adj[temp])
	        {
	            if(--inDegree[i]==0)
	            {
	                q.push(i);
	            }
	        }
	    }
	}
    bool isCyclic(int v, vector<int> adj[]) {
	    vector<int> inDegree(v, 0);
	    for (int j = 0; j < v; j++)
        {
            for (auto &i : adj[j]) 
            {
                inDegree[i]++;
            }
        }
	    
	    int ans=0;
	    bfs(adj, ans, inDegree, v);
	    return ans!=v;
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