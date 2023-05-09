//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    int posCount=0, negCount=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0) posCount++;
	        if(arr[i]<0) negCount++;
	    }
	    
	    int pos[posCount], neg[negCount], j=0, k=0, i;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            pos[j++]=arr[i];
	        }
	        else
	        {
	            neg[k++]=arr[i];
	        }
        }
	    j=k=i=0;
	    while (j < posCount && k < negCount) {
        arr[i++] = pos[j++];
        arr[i++] = neg[k++];
    }

    while (j < posCount) {
        arr[i++] = pos[j++];
    }

    while (k < negCount) {
        arr[i++] = neg[k++];
    }
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends