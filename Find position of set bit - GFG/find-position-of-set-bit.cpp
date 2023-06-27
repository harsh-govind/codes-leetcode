//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        // code here
        int count=0, pos=-1, i=1;
        while(n>0)
        {
            if(n&1)
            {
                pos=i;
                count++;
            }
            if(count>1)
            {
                return -1;
            }
            n=n>>1;
            i++;
        }
        return pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends