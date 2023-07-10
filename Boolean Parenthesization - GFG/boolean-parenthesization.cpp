//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> m;
    int solve(string &s, int i, int j, bool isTrue)
    {
        if(i>j) return 0;
        
        if(i==j)
        {
            if(isTrue)
            {
                return s[i]=='T';
            }
            else
            {
                return s[i]=='F';
            }
        }
        
        string temp= to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        
        if(m.find(temp)!=m.end())
        {
            return m[temp];
        }
        
        int ans=0;
        for(int k=i+1; k<=j-1; k+=2)
        {
            int leftTrue=solve(s,i, k-1, true);
            int leftFalse=solve(s, i, k-1, false);
            int rightTrue=solve(s, k+1, j, true);
            int rightFalse=solve(s, k+1, j, false);
            
            if(s[k]=='&')
            {
                if(isTrue)
                {
                    ans+=leftTrue*rightTrue;
                }
                else
                {
                    ans+=leftFalse*rightFalse+rightFalse*leftTrue+leftFalse*rightTrue;
                }
            }
            else if(s[k]=='|')
            {
                if(isTrue)
                {
                    ans+=leftTrue*rightTrue+leftTrue*rightFalse+rightTrue*leftFalse;
                }
                else
                {
                    ans+=leftFalse*rightFalse;
                }
            }
            else  //^
            {
                if(isTrue)
                {
                    ans+=leftTrue*rightFalse+rightTrue*leftFalse;
                }
                else
                {
                    ans+=leftTrue*rightTrue + leftFalse*rightFalse;
                }
            }
        }
        
        return m[temp]=ans%1003;
        
    }
    int countWays(int n, string s){
        // code here
        m.clear();
        return solve(s, 0, n-1, 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends