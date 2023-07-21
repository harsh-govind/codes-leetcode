//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(vector<int>adj[], int node, vector<int> &colors, int v)
    {
        colors[node]=0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            
            for(auto &i:adj[temp])
            {
                if(colors[i]==-1)
                {
                    colors[i]=!colors[temp];
                    q.push(i);
                }
                else if(colors[temp]==colors[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int> colors(v, -1);
	    
	    for(int i=0; i<v; i++)
	    {
	        if(colors[i]==-1)
	        {
	            if(!bfs(adj, i, colors, v)) return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends