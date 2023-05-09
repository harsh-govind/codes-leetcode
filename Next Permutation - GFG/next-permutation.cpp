//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int slightlyLessIdx=-1, slightlyGreaterIdx=0;
        for(int i=n-1; i>0; i--)
        {
            if(arr[i-1]<arr[i])
            {
                slightlyLessIdx=i-1;
                break;
            }
        }
        if(slightlyLessIdx==-1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        for(int i=n-1; i>=slightlyLessIdx; i--)
        {
            if(arr[i]>arr[slightlyLessIdx])
            {
                slightlyGreaterIdx=i;
                break;
            }
        }
        swap(arr[slightlyGreaterIdx], arr[slightlyLessIdx]);
        
        reverse(arr.begin()+slightlyLessIdx+1, arr.end());
        
        return arr;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends