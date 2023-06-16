//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], int currCol, int node, int color[], int n)
    {
        for(int k=0; k<n; k++)
        {
            if(k!=node and graph[k][node] == 1 and color[k]==currCol)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(bool graph[101][101], int color[], int node, int m, int n)
    {
        if(node==n) return true;
        
        for(int k=1; k<=m; k++)
        {
            if(isSafe(graph, k, node, color, n))
            {
                color[node]=k;
                if(solve(graph, color, node+1, m, n)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0}, node=0;
        return solve(graph, color, node, m, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends