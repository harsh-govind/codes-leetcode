//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int nodesN,int edgesN, int src){
        vector<int> adj[nodesN];
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(nodesN, 1e9);
        ans[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto &it:adj[node])
            {
                if(ans[node]+1<ans[it])
                {
                    ans[it]=1+ans[node];
                    q.push(it);
                }
            }
        }
        
        for(auto &val:ans)
        {
            if(val==1e9) val=-1;
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends