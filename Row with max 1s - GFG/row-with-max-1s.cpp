//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int m, int n) {
	    //val col
	    pair<int, int> ans={INT_MIN, 0};
	    int i=0, j=n-1, curr;
	    
	    while(j>=0 and i<m)
	    {
	        while(i<m and arr[i][j]!=1)
	        {
	           i++;
	        }
	        
	        if(i>=m) break;
	        
	        while(j>0 and arr[i][j]==1 and arr[i][j-1]==1)
	        {
	            j--;
	        }
	        
	       curr=n-j;
	       if(curr>ans.first)
	       {
                ans.first=curr;
	            ans.second=i;
	       }
	       
	       i++;
	    }
	    
	    return ans.first==INT_MIN?-1:ans.second;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends