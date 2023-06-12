//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool check(vector<vector<int>> &m, int n, int newX, int newY, set<pair<int, int>> &vis)
    {
        return newX>=0 and newX<n and newY>=0 and newY<n and vis.find({newX, newY})==vis.end() and m[newX][newY]==1;
    }
    void solve(vector<vector<int>> &m, int n, int x, int y, vector<string> &ans, set<pair<int, int>> &vis, string &current)
    {
        if(x==n-1 and y==n-1)
        {
            ans.push_back(current);
            return;
        }
        
        //DLRU
        
        vis.insert({x, y});
        int newX, newY;
        
        //down
        newX=x+1;
        newY=y;
        if(check(m, n, newX, newY, vis))
        {
            current.push_back('D');
            solve(m, n, newX, newY, ans, vis, current);
            current.pop_back();
        }
        
        //left
        newX=x;
        newY=y-1;
        if(check(m, n, newX, newY, vis))
        {
            current.push_back('L');
            solve(m, n, newX, newY, ans, vis, current);
            current.pop_back();
        }
        
        //right
        newX=x;
        newY=y+1;
        if(check(m, n, newX, newY, vis))
        {
            current.push_back('R');
            solve(m, n, newX, newY, ans, vis, current);
            current.pop_back();
        }
        
        newX=x-1;
        newY=y;
        if(check(m, n, newX, newY, vis))
        {
            current.push_back('U');
            solve(m, n, newX, newY, ans, vis, current);
            current.pop_back();
        }
        
        
        vis.erase({x, y});
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0) return ans;
        set<pair<int, int>> vis;
        string current="";
        solve(m, n, 0, 0, ans, vis, current);
        //sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends