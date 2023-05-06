//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long maxSum=0, currSum=0, mx=INT_MIN;
        bool flag=true;
        for(int i=0; i<n; i++)
        {
            currSum+=arr[i];
            if(arr[i]>0)
            {
                flag=false;
            }
            mx=max(int(arr[i]), int(mx));
            maxSum=max(currSum, maxSum);
            
            if(currSum<0)
            {
                currSum=0;
            }
            
        }
        if(flag)
        {
            return mx;
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends