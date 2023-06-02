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
        unordered_set<int> possible;
        for(int i=0; i<n; i++)
        {
            int flag=true;
            for(int j=0; j<n; j++)
            {
                if(m[i][j]==1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                possible.insert(i);
            }
        }
        
        vector<int> col;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=0; j<n; j++)
            {
                sum+=m[j][i];
            }
            col.push_back(sum);
        }
        for(auto &val:possible)
        {
            if(col[val]==n-1)
            {
                return val;
            }
        }
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