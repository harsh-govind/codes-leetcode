//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            s.push(i);
        }
        
        while(s.size()>=2)
        {
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            
            //if i knows j then j may be the celebrity
            if(m[i][j]==1)
            {
                s.push(j);
            }
            else
            {
                s.push(i);
            }
        }
        int possible=s.top(), rowSum=0, colSum=0;
        for(int i=0; i<n; i++)
        {
            rowSum+=m[possible][i];
            colSum+=m[i][possible];
        }
        if(colSum==n-1 and rowSum==0) return possible;
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends