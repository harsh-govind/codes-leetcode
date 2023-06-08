//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int trailingZeroes(int n) 
        {
            int ans=0;
            while(n)
            {
                ans+=n/5;
                n/=5;
            }
            return ans;
        }
        int findNum(int n)
        {
        //complete the function here
            int low=0, high=n*5, ans=-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int zeros=trailingZeroes(mid);
                if(zeros>=n)
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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends