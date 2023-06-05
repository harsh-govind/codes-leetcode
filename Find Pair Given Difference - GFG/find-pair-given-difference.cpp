//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int x){
    //code
    sort(arr, arr+n);
    int low=0, high=1;
    
    while(low<n and high<n)
    {
        int diff=arr[high]-arr[low];
        if(diff==x) return true;
        else if(diff<x) high++;
        else low++;
        
        if(high==low) high++;
    }
    
    return false;
    
    
}