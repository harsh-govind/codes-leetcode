//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution{
public:
    long long solve(int n, vector<long long> &dp)
    {
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        long long current = (n-1)%MOD;
        long long op1=solve(n-1, dp)%MOD;
        long long op2=solve(n-2, dp)%MOD;
        
        long long ans = current*((op1+op2)%MOD);
        
        return dp[n]=ans%MOD;
    }
    long int disarrange(int n){
        // code here
        vector<long long> dp(n+1, -1);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends