//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long mod=1000000007;
    int nCr(int n, int r){
        // code here
            if (n < 0 || r < 0)
                return 0;

            if (n < r)
                return 0;

            if (n == r)
                return 1;
                
            n++;
            vector<vector < long long>> ans;
            for (int i = 0; i < n; i++)
            {
                vector<long long> temp;
                for (int j = 0; j <= i; j++)
                {
                    temp.push_back(1);
                }
                ans.push_back(temp);
            }

            for (int i = 2; i < n; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j])%mod;
                }
            }
            
            return ans[n-1][r]%mod;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends