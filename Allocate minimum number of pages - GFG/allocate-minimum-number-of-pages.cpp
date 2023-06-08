//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int books[], int n, int students, int mid)
    {
        int currStudent=1, sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=books[i];
            if(sum>mid)
            {
                currStudent++;
                sum=books[i];
            }
            if(currStudent>students)
            {
                return false;
            }
        }
        return true;
    }
    int findPages(int books[], int n, int students) 
    {
        //code here
        if(n<students)
        {
            return -1;
        }
        int low=*max_element(books, books+n), high=accumulate(books, books+n, 0), ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(books, n, students, mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends