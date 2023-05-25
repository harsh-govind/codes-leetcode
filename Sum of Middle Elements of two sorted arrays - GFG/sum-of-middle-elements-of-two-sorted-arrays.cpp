//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int nums1[], int nums2[], int n) {
        
        int n1, n2;
        n1=n2=n;
        
        int low=0, high=n1;
        
        while(low<=high)
        {
            int part1 = (low + high)/2;
            int part2= (n1+n2+1)/2-part1;
            
            int left1=part1==0?INT_MIN:nums1[part1-1];
            int left2=part2==0?INT_MIN:nums2[part2-1];
            
            int right1=part1==n1?INT_MAX:nums1[part1];
            int right2=part2==n2?INT_MAX:nums2[part2];
            
            if(left1<=right2 and left2<=right1)
            {
                if((n1+n2)%2==0)
                {
                    return (max(left1, left2)+min(right1, right2));
                }
                else
                {
                    return max(left1, left2);
                }
            }
            else if(left1>right2)
            {
                high=part1-1;
            }
            else
            {
                low=part1+1;
            }
        }
        
        return 2.0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends