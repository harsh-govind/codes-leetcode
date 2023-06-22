//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char, int> m;
        for(auto &c:s)
        {
            m[c]++;
        }
        priority_queue<int> p;
        for(auto &val:m)
        {
            p.push(val.second);
        }
        
        while(k--)
        {
            int x=p.top();
            p.pop();
            p.push(--x);
        }
        int ans=0;
        while(!p.empty())
        {
            ans+=p.top()*p.top();
            p.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends