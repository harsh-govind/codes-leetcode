//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string a, string b, int m, int n)
    {
        // your code here
        int t[m + 1][n + 1];
            for (int i = 0; i < n + 1; i++)
            {
                t[0][i] = 0;
            }
            for (int i = 0; i < m + 1; i++)
            {
                t[i][0] = 0;
            }

            for (int i = 1; i < m + 1; i++)
            {
                for (int j = 1; j < n + 1; j++)
                {
                    if (a[i - 1] == b[j - 1])
                    {
                        t[i][j] = 1 + t[i - 1][j - 1];
                    }
                    else
                    {
                        t[i][j] = 0;
                    }
                }
            }
            int ans=INT_MIN;
            
            for (int i = 1; i < m + 1; i++)
            {
                for (int j = 1; j < n + 1; j++)
                {
                    ans=max(ans, t[i][j]);
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends