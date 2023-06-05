//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> &nums, int n) {
        // code here
        // arrSum - nSum
        // arr2Sum - n2Sum
        long long arrSum = 0, arr2Sum = 0;
        for (auto& val : nums) {
            arrSum += static_cast<long long>(val);
            arr2Sum += static_cast<long long>(val) * static_cast<long long>(val);
        }
        long long x = arrSum - (static_cast<long long>(n) * (n + 1)) / 2;
        long long y = arr2Sum - (static_cast<long long>(n) * (n + 1) * (2 * n + 1)) / 6;
        y /= x;

        long long repeated = (x + y) / 2;
        long long missing = (repeated - x);

        return { static_cast<int>(repeated), static_cast<int>(missing) };
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends