//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {
            int i = 0, j = 0, t = 0;
    while (i < m and j < n and t < k)
    {
        if (arr1[i] < arr2[j])
        {
            t++;
            if (t == k)
            {
                return arr1[i];
            }
            i++;
        }
        else
        {
            t++;
            if (t == k)
            {
                return arr2[j];
            }
            j++;
        }
    }
    // Handle remaining elements in arr1 or arr2
    while (i < m and t < k)
    {
        t++;
        if (t == k)
        {
            return arr1[i];
        }
        i++;
    }
    while (j < n and t < k)
    {
        t++;
        if (t == k)
        {
            return arr2[j];
        }
        j++;
    }
    return -1; // If k is out of range
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends