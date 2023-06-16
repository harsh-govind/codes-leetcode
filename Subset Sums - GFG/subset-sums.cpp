//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int i, vector<int> &ans, int currSum, int n, vector<int> &arr)
    {
        if(i==n)
        {
            ans.push_back(currSum);
            return;
        }
        
        //include
        currSum+=arr[i];
        solve(i+1, ans, currSum, n, arr);
        currSum-=arr[i];
        
        //exclude
        solve(i+1, ans, currSum, n, arr);
        
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0, ans, 0, n, arr);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends