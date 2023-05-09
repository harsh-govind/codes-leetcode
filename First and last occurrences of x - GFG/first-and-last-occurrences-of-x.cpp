//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
   vector<int> ans;
   auto it=lower_bound(arr, arr+n, x),  it2=upper_bound(arr, arr+n, x);
   if(it==(arr+n) or *it!=x)
   {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
   }
   ans.push_back(it-arr);
   ans.push_back(it2-arr-1);
   return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends