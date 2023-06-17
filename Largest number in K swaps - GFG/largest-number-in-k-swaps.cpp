//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void solve(string &s, int k, string &ans, int idx)
    {
        ans=max(ans, s);
        
        if(k==0)
        {
            return;
        }
        
        char maxNo=s[idx];
        for(int i=idx+1; i<s.size(); i++)
        {
            maxNo=max(maxNo, s[i]);
        }
        
        if(s[idx]!=maxNo) k--;
        
        for(int i=idx; i<s.size(); i++)
        {
            if(s[i]==maxNo)
            {
                swap(s[i], s[idx]);
                solve(s, k, ans, idx+1);
                swap(s[i], s[idx]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans;
       solve(str, k, ans, 0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends