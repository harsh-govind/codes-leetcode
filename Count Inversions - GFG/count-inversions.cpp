//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans=0;
     long long  an;
    void merge(long long a[],  long long  l,  long long  m,  long long  h)
    {
         long long  temp[an], i=l, j=m, k=0;
        while(i<m and j<=h)
        {
            if(a[i]<=a[j])
            {
                temp[k++]=a[i++];
            }
            else
            {
                temp[k++]=a[j++];
                
                ans+=(m-i);
            }
            
        }
        
        while(i<m)
        {
            temp[k++]=a[i++];
        }
        while(j<=h)
        {
            temp[k++]=a[j++];
        }
        k=0;
        for(int i=l; i<=h; i++)
        {
            a[i]=temp[k++];
        }
    }
    void mergeSort(long long arr[],  long long  l,  long long  h)
    {
         long long  m=(l+h)/2;
        if(l<h)
        {
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, h);
            
            merge(arr, l, m+1, h);
            
        }
    }
    long long int inversionCount(long long arr[], long long n)
    {
        an=n;
        mergeSort(arr, 0, n-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends