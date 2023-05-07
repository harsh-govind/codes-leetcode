//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long a[], long long b[], int m, int n) 
        { 
            int c[m+n], i=0, j=0, k=0;
            
            while(i<m and j<n)
            {
                if(a[i]<b[j])
                {
                    c[k++]=a[i++];
                }
                else if(a[i]>b[j])
                {
                    c[k++]=b[j++];
                }
                else
                {
                    c[k++]=a[i++];
                    c[k++]=b[j++];
                }
            }
            
            for(;i<m; i++)
            {
                c[k++]=a[i];
            }
            for(;j<n;j++)
            {
                c[k++]=b[j];
            }
            
            k=0;
            
            for(i=0; i<m; i++)
            {
                a[i]=c[k++];
            }
            for(i=0; i<n;i++)
            {
                b[i]=c[k++];
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends