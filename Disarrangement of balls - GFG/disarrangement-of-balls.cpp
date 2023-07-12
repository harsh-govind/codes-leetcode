//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution{
public:
    long int disarrange(int n){
        // code here
        long long prev2=0, prev1=1;
        
        for(int i=3; i<=n; i++)
        {
            long long current = (i-1)%MOD;
            long long op1=prev1%MOD;
            long long op2=prev2%MOD;
            
            long long ans = current*((op1+op2)%MOD);
            
            prev2=prev1;
            prev1=ans%MOD;
        }
        return prev1;
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