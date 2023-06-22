//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) 
{
    queue<long long int> q;
    for(int i=0; i<k-1; i++)
    {
       if(a[i]<0) q.push(a[i]);
    }
    
    int i=k-1;
    vector<long long int> ans;
    while(i<n)
    {
        if(a[i]<0) q.push(a[i]);
        if(q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
            
            if(q.front()==a[i-k+1])
            {
                q.pop();
            }
        }
        i++;
    }
    return ans;
 }