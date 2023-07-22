//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort( vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &stk, int node)
    {
        visited[node]=true;
        for(auto &it:adj[node])
        {
            int i=it.first;
            if(!visited[i])
            {
                topoSort(adj, visited, stk, i);
            }
        }
        stk.push(node);
    }
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[n];
        
        for(int i=0; i<m; i++)
        {
            int u=edges[i][0], v=edges[i][1], w=edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        vector<bool> visited(n, false);
        stack<int> stk;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                topoSort(adj, visited, stk, i);
            }
        }
        
        vector<int> ans(n, 1e9);
        
        ans[0]=0;
        
        while(!stk.empty())
        {
            int node=stk.top();
            stk.pop();
            
            for(auto &it:adj[node])
            {
                int v=it.first, wt=it.second;
                
                if(ans[node]+wt < ans[v])
                {
                    ans[v]=ans[node]+wt;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(ans[i]==1e9)
            {
                ans[i]=-1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends