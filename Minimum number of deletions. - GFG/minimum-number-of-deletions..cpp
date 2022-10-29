//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string a, int n) { 
            string b = a;
            reverse(b.begin(), b.end());
            int m = a.size();
            n = b.size();
            int t[m + 1][n + 1];
            for (int i = 0; i < m + 1; i++)
            {
                t[i][0] = 0;
            }
            for (int i = 0; i < n + 1; i++)
            {
                t[0][i] = 0;
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
                        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                    }
                }
            }

            return m-t[m][n];

} 