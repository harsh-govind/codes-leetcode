//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int, int> s;
        int ans=0, i=0, sum=0;
        while(i<n)
        {
            sum+=a[i];
            if(sum==0)
            {
                ans=max(ans, i+1);
            }
            else if(s.find(sum)!=s.end())
            {
                ans=max(ans, i-s[sum]);
            }
            else
            {
                s[sum]=i;
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends